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


void add(){

}

void find(){

}

int main(int argc, char *argv[]){
    string filename(argv[1]);
    ifstream input(filename);
  
    if (!input.is_open()) {
        cerr << "Could not open the file"
             << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    if(argv[1] == "find"){
        string filename(argv[2]);
        ifstream input(filename);
  
        if (!input.is_open()) {
            cerr << "Could not open the file"
                 << filename << "'" << endl;
             return EXIT_FAILURE;
        }
        string line;
        getline (input, line);
        string all = line;
        

    }
    if(argv[1] == "add"){
        string filename(argv[2]);
        ifstream input(filename);
  
        if (!input.is_open()) {
            cerr << "Could not open the file"
                 << filename << "'" << endl;
             return EXIT_FAILURE;
        }
    }
    
}