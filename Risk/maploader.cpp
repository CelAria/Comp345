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

GameMap* ptrgamemap= new GameMap();
//ptrgamemap =&gamemap;
//GameMap gamemap;


void Maploader::readmapfile(){
    //assign pointer to gamemap;
   // ptrgamemap =&gamemap;
    
    //string variable for each line parsed by fstream
    string line;
    //uses filename and fstream
    cout << "\nplease type the complete file path of the map file you would like to open. File must be of the type .map\n";
    getline (cin, filename);
    
    //reject if not a .map file
    if(filename.substr(filename.find_last_of(".") + 1) != "map"){
        cout << "file is not of type map. Try again with a valid .map file.\n";
        filename.clear();
        readmapfile();
        return;
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
            cout << " This gamemap is valid! Add any other maps you want:\n";
            readmapfile();
            return;
        }
        
      
        if(!ptrgamemap->isValid()){
        cout << "gamemap is invalid. It has been deleted. Try again with a valid map file\n";
        GameMap *ptrgamemap = new GameMap();
        readmapfile();
        return;
        }
        
    }
    else{
        cout << "\ncould not open file:" << " \"" << filename << "\"" << "\nTry again with a valid .map file\n";
        readmapfile();
        return;
    }
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
    Country country =Country(name, continentname);
    ptrgamemap->addCountry(name, continentname, neighbors);
    neighbors.clear();
}

