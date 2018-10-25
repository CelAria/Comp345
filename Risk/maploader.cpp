#include "maploader.h"
#include "gamemap.h"
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <fstream>
#include <iostream>

using namespace std;


GameMap* Maploader::readmapfile(string file){
   ptrgamemap = new GameMap();
    
    filename = file;
    //string variable for each line parsed by fstream
    string line;
    //uses filename and fstream
   
    //reject if not a .map file
    if(filename.substr(filename.find_last_of(".") + 1) != "map"){
        cout << "file is not of type map.";
        delete ptrgamemap;
        ptrgamemap= NULL;
        filename.clear();
    }
    
    fstream.open(filename);
    
    //if file opens succesfully
    if(fstream.is_open()){
        
        
        cout << "\n" << "\"" << filename << "\" " << "opened successfully\n";
        
        
        bool isInContinent = false;
        bool isInTerritory = false;
        
        while(!fstream.eof()){
            
            
            getline(fstream,line);
            
            //Removing the windows \r character"
            if(!line.empty() && *line.rbegin() == '\r') {
                line.erase( line.length()-1, 1);
            }
            
            if(line == "[Continents]") {
                isInContinent = true;
                isInTerritory = false;
                continue;
                
            } else if(line == "[Territories]") {
                isInContinent = false;
                isInTerritory = true;
                continue;
                
            } else if(line == "") {
                continue;
            }
            
            if(isInContinent) {
                parseContinent(line);
            }
            if(isInTerritory) {
                parseTerritory(line);
            }
            
        }
        
        fstream.close();
        cout << "end of file, stream successfully closed\n" << endl;
        
        
        //If map invalid, reject and offer readmap() again, if valid, accept
        
        if(ptrgamemap->isValid()){
            ptrgamemap->traverseAll(true);
            cout << " This gamemap is valid! \n";
        }
        
        
        if(!ptrgamemap->isValid()){
            cout << "gamemap is invalid. It has been deleted. Try again with a valid map file\n";
            delete ptrgamemap;
            ptrgamemap= NULL;
        }
        
    }
    else{
        cout << "\ncould not open file:" << " \"" << filename << "\"" << "\nTry again with a valid .map file\n";
    }
    return ptrgamemap;
}

GameMap* Maploader::readmapfile(){
    ptrgamemap = new GameMap();
    
    //string variable for each line parsed by fstream
    string line;
    //uses filename and fstream
    cout << "\nplease type the complete file path of the map file you would like to open. File must be of the type .map. Do not include quotation marks in the file path.\n";
    getline (cin, filename);
    
    //reject if not a .map file
    if(filename.substr(filename.find_last_of(".") + 1) != "map"){
        cout << "file is not of type map. Try again with a valid .map file.\n";
        delete ptrgamemap;
        ptrgamemap= NULL;
        filename.clear();
        readmapfile();
    }
    
    fstream.open(filename);
    
    //if file opens succesfully
    if(fstream.is_open()){
        
        
        cout << "\n" << "\"" << filename << "\" " << "opened successfully\n";
        
        //make gamemap (only one for program)
        
        bool isInContinent = false;
        bool isInTerritory = false;
        
        while(!fstream.eof()){
    
            
            getline(fstream,line);
            
            //Removing the windows \r character"
            if(!line.empty() && *line.rbegin() == '\r') {
                line.erase( line.length()-1, 1);
            }
            
            if(line == "[Continents]") {
                isInContinent = true;
                isInTerritory = false;
                continue;
                
            } else if(line == "[Territories]") {
                isInContinent = false;
                isInTerritory = true;
                continue;
                
            } else if(line == "") {
                continue;
            }
           
                if(isInContinent) {
                    parseContinent(line);
                }
                if(isInTerritory) {
                    parseTerritory(line);
                }
        
        }
        
        fstream.close();
        cout << "end of file, stream successfully closed\n" << endl;
        
        
        //If map invalid, reject and offer readmap() again, if valid, accept
        
        if(ptrgamemap->isValid()){
            ptrgamemap->traverseAll(true);
            cout << " This gamemap is valid!\n" << endl;
        }
        
      
        if(!ptrgamemap->isValid()){
        cout << "gamemap is invalid. It has been deleted. Try again with a valid map file\n";
        delete ptrgamemap;
        ptrgamemap= NULL;
        readmapfile();
        }
        
    }
    else{
        cout << "\ncould not open file:" << " \"" << filename << "\"" << "\nTry again with a valid .map file\n";
        readmapfile();
    }
    return ptrgamemap;
}

void Maploader::parseContinent(string line) {
    //for each token, push into the array of tokens.
    
    cout <<  line  << endl;
    std::string token;
    char delimiter = '=';
    
    std::stringstream ss(line);
    
    std::getline(ss, token, delimiter);
    name = token;
    
    std::getline(ss, token, delimiter);
    points = stoi(token);
    
    Continent continent = Continent(name, points);
    ptrgamemap->addContinent(continent);
}

void Maploader::parseTerritory(string line) {
   
    cout <<  line  << endl;
    std::string token;
    char delimiter = ',';
    
    std::stringstream ss(line);
    
    std::getline(ss, token, delimiter);
    name = token;
    
    std::getline(ss, token, delimiter);
    xcoord = token;
    
    std::getline(ss, token, delimiter);
    ycoord = token;
    
    std::getline(ss, token, delimiter);
    continentname = token;
   
    while(std::getline(ss, token, delimiter)){
         neighbor = token;
         neighbors.push_back(token);
    }
    
    ptrgamemap->addCountry(name, continentname, neighbors);
    neighbors.clear();
}

