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


static void Maploader::parser(string line){
    //loop for each line of the .map file
    while(getline(mystream,line)){
        // if the current line is "[continents]"
        if(line==continents){
        //go to next line
        //for every line that isn't "[territories]" AKA WHILE CONTINENTS
          while(line != territories){
          //tokenize the line. Read characters into name until "=". read int into points
          char split_char= '=';
          for(string each; getline(mystream,each, split_char); token.push_back(each));
            name=token[0];
            cout << name << endl;
            //cast to int
            points=stoi(token[1]);
            cout << points << endl;
            Continent(name, points);
          }
        }
        
        if(line==territories){
          string countryname;
          string continentname;
          //go to next line
          getline(mystream, line);
          //for each line, until a COMMA is found, create a new country name
          // MULTIPLE SPLIT CHARACTERS: comma, all numvrers
          char split_charcomma = ',';
          char split_char0 = '0';
          char split_char1 = '1';
          char split_char2 = '2';
          char split_char3= '3';
          char split_char4= '4';
          char split_char5= '5';
          char split_char6= '6';
          char split_char7= '7';
          char split_char8= '8';
          char split_char9= '9';

          vector<string> token;
//          for(string each; getline(mystream,each,(split_char0 || split_char1 || split_char2 || split_char3 || split_char4 || split_char5 ||split_char6 || split_char7 || split_char8 || split_char9)); token.push_back(each));{
            countryname =token[0];
            continentname =token[1];
            cout << countryname << endl;
            cout << continentname << endl;
            //new pointer for country
            //Create new country object
            Country(countryname, continentname);
            
          //skip all numbers
          //NEXT token is continent
          //each token afterwards as a country "neighbour"
          for (int i=2; i < token.size(); i++){
            //create new country object where token[i] is name
            //add continent info
            //TEST IF ALREADY A COUNTRY!!
            string neighbourcountry;
            Country(token[i], continentname);
            //HOW TO ADD NEIGHBOUR???? NEED TO DO
            //this.addNeighbour(neighbour);

          }
        }
    }

static void Maploader::readmapfile(){
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
      //make gamemap (only one for program)
        GameMap gamemap;
        //HOW TO CALL PARSER FUNCTION **TO DO***
        //parser(line);
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


