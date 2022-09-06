#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std; 

/*
 *  * Split function I found at https://stackoverflow.com/questions/289347/using-strtok-with-a-stdstring
 *   */
void split(const string& str, const string& delim, vector<string>& parts) {
  size_t start, end = 0;
  while (end < str.size()) {
    start = end;
    while (start < str.size() && (delim.find(str[start]) != string::npos)) {
      start++;  // skip initial whitespace
    }
    end = start;
    while (end < str.size() && (delim.find(str[end]) == string::npos)) {
      end++; // skip to end of word
    }
    if (end-start != 0) {  // just ignore zero-length strings.
      parts.push_back(string(str, start, end-start));
    }
  }
}

string getData(string file){
 ifstream input(file);
  
    if (!input.is_open()) {
        cerr << "Could not open the file"
             << file << "'" << endl;
        exit(1);
    }
  string line;
  getline (input, line);
  string all = line;
  return all;

}

int main(int argc, char *argv[]){
    string filename(argv[2]);
    string choice = argv[1];

    if(choice == "find"){
      string all = getData(filename);
      cout<<all;
    }
    if(choice == "add"){
        }
    }
    
