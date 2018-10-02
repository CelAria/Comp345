#include "maploader.h"
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <fstream>
#include <iostream>
using namespace std;

/*free function to read in map file and parse */ 

  static void readmap(){

    string filename;
    ifstream fstream; 

    cout << "\nplease type the name of the map file you would like to open. File must be of the type .map\n";   
    getline (cin, filename);

    //reject if not a .map file
    if(filename.substr(filename.find_last_of(".") + 1) != "map"){
      cout << "file is not of type map. Try again with a valid .map file.\n";
      filename.clear();
      readmap();
      return;
    }

    fstream.open("include/" + filename);
    //if file opens succesfully
    if(fstream.is_open()){
      cout << "\n" << "\"" << filename << "\" " << "opened successfully\n";
      fstream.close();
      cout << "stream successfully closed\n";
      return;
    }
    else{
      cout << "\ncould not open file:" << " \"" << "include/" << filename << "\"" << "\nTry again with a valid .map file\n"; 
      readmap();
      return;
    }
  }

int main(){
readmap(); 
return 0;
}