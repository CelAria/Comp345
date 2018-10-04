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

/*free function to read in map file and parse */

static void readmapfile(){
    
    string filename;
    ifstream fstream;
    
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
        GameMap gamemap;
        fstream.close();
        cout << "stream successfully closed\n";
        return;
    }
    else{
        cout << "\ncould not open file:" << " \"" << "include/" << filename << "\"" << "\nTry again with a valid .map file\n";
        readmapfile();
        return;
    }
}

static void parser(ifstream mystream){
    //loop for each line of the .map file
    string line;
    string continents= "[Continents]";
    string territories= "[Territories]";
    
    while(getline(mystream,line)){
        // if the current line is "[continents]"
        if(line==continents){
            //go to next line
            getline(mystream,line);
            //for every line that isn't "[territories]" AKA WHILE CONTINENTS
            while(line != territories){
                //tokenize the line. Read characters into name until "=". read int into points
//                string name;
//                int points;
//                char* token;
//                //make one token until it sees =
//                token =strtok(line, "=");
//                name = token;
//                token=strtok(NULL, "=");
//                points= token;
//                //new continent
//                Continent(name, points);
            }
        }
        if(line==territories){
            string name;
            string continentname;
            //go to next line
            getline(mystream, line);
            //for each line, until a COMMA is found, create a new country name
            //skip all numbers
            //NEXT token is continent
            //each token afterwards as a country "neighbour"
            Country(name, continentname);
        }
    }
}



int main(){
    readmapfile();
    return 0;
}
