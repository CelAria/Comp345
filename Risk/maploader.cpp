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

int j=1;

//trim off the end line characters from each line
std::string& rtrim(std::string& str) {
    size_t endpos = str.find_last_not_of("\r");
    if(endpos != std::string::npos) {
        str.substr(0,endpos+1).swap(str);
    }
    return str;
}
std::string& ntrim(std::string& str) {
    size_t endpos = str.find_last_not_of("\n");
    if(endpos != std::string::npos) {
        str.substr(0,endpos+1).swap(str);
    }
    return str;
}

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
        GameMap gamemap;
        cout << "gamemap created" << endl << endl;
        //HOW TO CALL PARSER FUNCTION **TO DO***
        
        //WHILE THERE ARE LINES IN THE FILE TO PARSE
        while(true){
            cout << "entered while there are lines in the file loop" << endl << endl;
            
            if(fstream.eof()){
                //if end of file reached, close stream.
                fstream.close();
                cout << "end of file, stream successfully closed\n";
                return;
            }
            cout << "entering parser function" << endl;
            parser(line);
            cout << "parser function completed" << endl << endl;
        }
    }
    else{
        cout << "\ncould not open file:" << " \"" << filename << "\"" << "\nTry again with a valid .map file\n";
        readmapfile();
        return;
    }
}

void Maploader::parser(string line){
    //remove trailing character from lines
    //loop for each line of the .map file
    while(getline(fstream,line)){
        cout << "entered main parser getline loop" << endl;
        // if the current line is "[continents]"
        rtrim(continents);
        rtrim(territories);
        if(line==(continents) && line != territories){
            cout << "entered section of map file \"CONTINENTS\"" << endl;
                char split_char= '=';
                //for each token, push into the array of tokens.
                for(string each; getline(fstream,ntrim(each),split_char);){
                    cout << each << endl;
                    token.push_back(each);
                    if(token.size()==2){
                        cout << token.size() << " token size" << endl;
                        cout << "token[0]:" << token[0] << " token [1]:" << token[1] << " end" << endl;
                        //the name of the continent is value of token array at 0.
                        name=token[0];
                        cout << name << " is name" << endl;
                        cout << token[0] << " is token at 0" << endl;
                            cout << token[1] << " is token at 1" << endl;
                        //cast to int
                        points=stoi(token[1]);
                        cout << points << " is points" << endl;
                        Continent(name, points);
                        //clear vector array
                        token.clear();
                        fstream.ignore();
                     }
                 }
            }
        if(line==territories){
            //go to next line
           // getline(fstream, line);
            //for each line, until a COMMA is found, create a new country name
            // MULTIPLE SPLIT CHARACTERS: comma
            char split_charcomma = ',';
            vector<string> tokens;
            for(string eachtoken; getline(fstream,eachtoken,split_charcomma); tokens.push_back(eachtoken)){
                countryname =tokens[0];
                cout << tokens.size() <<  " tokens size" << endl;
                continentname =token[1];
                //these variables will not be used (for now)
                int xcoord = stoi(token[2]);
                int ycoord = stoi(token[3]);
                //
                cout << countryname << " is country name" << endl;
                cout << continentname << " is continent name" << endl;
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
        else{
            cout << line << " this is the line ^" << endl;
            cout << "line equals neither!!" << endl;
            cout << j++ << " number of lines" << endl;
            cout << endl;
        }
    }
}
