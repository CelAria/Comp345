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

//default constructor
Maploader::Maploader(){}

//destructor
Maploader::~Maploader(){}

void Maploader::readmapfile(){
    //string variable for each line parsed by fstream
    string line;
    //uses filename and fstream
    cout << "\nplease type the name of the map file you would like to open. File must be of the type .map\n";
    getline (cin, filename);
    
    //reject if not a .map file
    if(filename.substr(filename.find_last_of(".") + 1) != "map"){
        cout << "file is not of type map. Try again with a valid .map file.\n";
        filename.clear();
        readmapfile();
        return;
    }
    
    fstream.open("include/" + filename);
    
    //if file opens succesfully
    if(fstream.is_open()){
        cout << "\n" << "\"" << filename << "\" " << "opened successfully\n";
        
        //make gamemap (only one for program)
        GameMap gamemap;
        //HOW TO CALL PARSER FUNCTION **TO DO***
        
        //WHILE THERE ARE LINES IN THE FILE TO PARSE
        while(true){
            if(fstream.eof()){
                //if end of file reached, close stream.
                fstream.close();
                cout << "stream successfully closed\n";
                return;
            }
            getline(fstream, line);
            parser(line);
        }
    }
    else{
        cout << "\ncould not open file:" << " \"" << "include/" << filename << "\"" << "\nTry again with a valid .map file\n";
        readmapfile();
        return;
    }
}


void Maploader::parser(string line){
    //loop for each line of the .map file
    while(getline(fstream,line)){
        // if the current line is "[continents]"
        if(line==continents){
            //go to next line
            //for every line that isn't "[territories]" AKA WHILE CONTINENTS
            while(line != territories){
                //tokenize the line. Read characters into name until "=". read int into points
                char split_char= '=';
                for(string each; getline(fstream,each,split_char); token.push_back(each)){
                    name=token[0];
                    cout << name << endl;
                    //cast to int
                    points=stoi(token[1]);
                    cout << points << endl;
                    Continent(name, points);
                }
            }
        }
        if(line==territories){
            //go to next line
            getline(fstream, line);
            //for each line, until a COMMA is found, create a new country name
            // MULTIPLE SPLIT CHARACTERS: comma
            char split_charcomma = ',';
            for(string each; getline(fstream,each,split_charcomma); token.push_back(each)){
                countryname =token[0];
                continentname =token[1];
                int xcoord = stoi(token[2]);
                int ycoord = stoi(token[3]);
                //
                cout << countryname << endl;
                cout << continentname << endl;
                //new pointer for country
                //Create new country object
                Country(countryname, continentname);
                for (int t=3; (token.size())-4.0; t++){
                    //LOOP FOR ADDING NEIGHBOUR COUNTRIES
                    string neighbourcountry = token[t];
                    //create NEW country object (with name token[i] and continent token[1]
                    Country(token[t],token[1]);
                    //add neighbours (USE .addneighbours function)
                }
            }
        }
    }
    
    //uses filename and fstream
    cout << "\nplease type the name of the map file you would like to open. File must be of the type .map\n";
    getline (cin, filename);
    
    //reject if not a .map file
    if(filename.substr(filename.find_last_of(".") + 1) != "map"){
        cout << "file is not of type map. Try again with a valid .map file.\n";
        filename.clear();
        readmapfile();
        return;
    }
    
    fstream.open("include/" + filename);
    
    //if file opens succesfully
    if(fstream.is_open()){
        cout << "\n" << "\"" << filename << "\" " << "opened successfully\n";
        
        //make gamemap (only one for program)
        GameMap gamemap;
        //HOW TO CALL PARSER FUNCTION **TO DO***
        
        //WHILE THERE ARE LINES IN THE FILE TO PARSE
        while(true){
            if(fstream.eof()){
                //if end of file reached, close stream.
                fstream.close();
                cout << "stream successfully closed\n";
                return;
            }
            getline(fstream, line);
            parser(line);
        }
    }
    else{
        cout << "\ncould not open file:" << " \"" << "include/" << filename << "\"" << "\nTry again with a valid .map file\n";
        readmapfile();
        return;
    }
}

