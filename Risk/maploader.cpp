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

GameMap gamemap;


void Maploader::readmapfile(){
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
            cout << "entered while there are lines in the file loop" << endl << endl;
            
            cout << "entering parser function" << endl;
            
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
        cout << "end of file, stream successfully closed\n";
        
        
        //If map invalid, reject and offer readmap() again, if valid, accept
        
        if(gamemap.isValid()){
            cout << "gamemap is valid! There are " << gamemap.isValid() << " countries in this map. Add any other maps you want:\n";
        }
        
      
        if(!gamemap.isValid()){
        gamemap.~GameMap();
        cout << "gamemap is invalid. It has been deleted. Try again with a valid map file\n";
        return;
        }
        
        readmapfile();
    }
    else{
        cout << "\ncould not open file:" << " \"" << filename << "\"" << "\nTry again with a valid .map file\n";
        readmapfile();
        return;
    }
}

void Maploader::parseContinent(string line) {
    cout << "entered section of map file \"CONTINENTS\"" << endl;
    //for each token, push into the array of tokens.
    
    cout <<  line << "***" << endl;
    std::string token;
    char delimiter = '=';
    
    std::stringstream ss(line);
    
    std::getline(ss, token, delimiter);
    name = token;
    cout << name << " is name" << endl;
    
    std::getline(ss, token, delimiter);
    points = stoi(token);
    cout << points << " this is points" << endl;
    
    Continent continent = Continent(name, points);
    gamemap.addContinent(continent);
}

void Maploader::parseTerritory(string line) {
    cout << "entered section of map file \"TERRITORIES\"" << endl;
   
    cout <<  line << "***" << endl;
    std::string token;
    char delimiter = ',';
    
    std::stringstream ss(line);
    
    std::getline(ss, token, delimiter);
    name = token;
    cout << name << " is name" << endl;
    
    std::getline(ss, token, delimiter);
    xcoord = stoi(token);
    cout << xcoord << " this is xcoord" << endl;
    
    std::getline(ss, token, delimiter);
    ycoord = stoi(token);
    cout << ycoord << " this is ycoord" << endl;
    
    std::getline(ss, token, delimiter);
    continentname = token;
    cout << continentname << " this is continent name" << endl;
   
    while(std::getline(ss, token, delimiter)){
         neighbor = token;
         neighbors.push_back(token);
        cout << token << " this is a neighbor" << endl;
    }
    Country country =Country(name, continentname);
    gamemap.addCountry(name, continentname, neighbors);
}

