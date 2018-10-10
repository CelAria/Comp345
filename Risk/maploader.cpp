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

void Maploader::parser(string line){
    //loop for each line of the .map file
    while(getline(mystream,line)){
        // if the current line is "[continents]"
        if(line==continents){
        //go to next line
        //for every line that isn't "[territories]" AKA WHILE CONTINENTS
          while(line != territories){
          //tokenize the line. Read characters into name until "=". read int into points
          char split_char= '=';
          for(string each; getline(mystream,each,split_char); token.push_back(each));
            name=token[0];
            cout << name << endl;
            //cast to int
            points=stoi(token[1]);
            cout << points << endl;
            Continent(name, points);
          }
        }
        
        if(line==territories){
          //go to next line
          getline(mystream, line);
          //for each line, until a COMMA is found, create a new country name
          // MULTIPLE SPLIT CHARACTERS: comma
          char split_charcomma = ',';
          for(string each; getline(mystream,each,split_charcomma); token.push_back(each));{
            countryname =token[0];
            continentname =token[1];
            xcoord = token[2];
            ycoord = token[3];
              //
              cout << countryname << endl;
              cout << continentname << endl;
              //new pointer for country
              //Create new country object
              Country(countryname, continentname);
              for (t=3; (token.size())-4.0; t++){
                  //LOOP FOR ADDING NEIGHBOUR COUNTRIES
                  string neighbourcountry = token[t];
                  //create NEW country object (with name token[i] and continent token[1]
                  Country(token[i],token[1]);
                  //add neighbours (USE .addneighbours function)
              }
        }
    }

void Maploader::readmapfile(){
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
        parser(line);
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

  //function for tokenizing the "continents" section
/*   void tokenizeContinents(const string& str, vector<string>& tokens, const string& delimiters = "=")
  {
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}

  void tokenizeTerritories(const string& str, vector<string>& tokens){
    boost::char_seperator<char> sep("=");
    typedef boost::tokenizer<boost::char_seperator<char>> t_tokenizer;
    t_tokenizer tok(str,sep);
    for(t_tokenizer::iterator beg= tok.begin(); beg !=tok.end(); ++beg){
      cout << *beg << "\n"
    }
  }
 */


