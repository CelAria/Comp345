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
    vector<string> vec;
            for(string line; getline(fstream, line ); )
            {vec.push_back(line);}
            cout << "entered main parser getline loop" << endl;
            // if the current line is "[continents]"
           //rtrim(continents);
           //rtrim(territories);
    
    
    for(int t=0; t <= vec.size(); t++) {
        //print each line
        cout << vec[t] << "*****" << endl;
            if(vec[t]==(continents) && vec[t]!= territories){
                while(vec[t]!= territories){
                    cout << "entered section of map file \"CONTINENTS\"" << endl;
                    //for each token, push into the array of tokens.
                    int t2=t+1;
                    cout <<  vec[t2] << "***" << endl;
                    std::string token;
                    char delimiter = '=';
                    vector<string> objectinfo;
                    std::stringstream ss(vec[t2]);
                    while (std::getline(ss, token, delimiter)) {
                        objectinfo.push_back(token);
                        cout << token << " token [from continents loops]" << endl;
                if(objectinfo.size()==2){
                    name=objectinfo[0];
                    cout << name << " this is name" << endl;
                    points=stoi(objectinfo[1]);
                    cout << points << " this is points" << endl;
                    cout << endl;
                    Continent(name, points);
                    objectinfo.clear();
                    }
                 }
                t++;
                }
            }
            if(vec[t]==(territories)){
                cout << "entered territory loop" <<endl;
                int t2 =0;
                int c;
                c= vec.size()-t;
                cout << c << " size of vec" << endl;
                for(int j=0; j < c; j++)
              {

                  cout << "entered non EOF" << endl;
                //go to next line
                t2++;
               //rtrim(vec[t2]);
                cout <<  vec[t2] << " ***" << endl;
                std::string token;
                std:string continent;
                char delimiter = ',';
                vector<string> objectinfo;
                std::stringstream ss(vec[t2]);
                while (std::getline(ss, token, delimiter)) {
                    objectinfo.push_back(token);
                    cout << token << " this is the token" << endl;
                }
                    // add object info
                    //if empty, return.
                        //if(token.empty()){ cout << "empty line" << endl; return;}
                        name=objectinfo[0];
                        cout << name << " this is name" << endl;
                        continent=(objectinfo[3]);
                        cout << continent << " this is continent" << endl;
                        cout << endl;
                        Country(name, continent);
                  for(int h= 4; h < objectinfo.size(); h++){
                    /** ADD NEIGHBOURS ** PUSH INTO GAMEMAP **/
                     // addNeighbor(objectinfo[h]);
                  }
                        objectinfo.clear();
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
