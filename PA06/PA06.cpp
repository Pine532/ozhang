#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <stack>
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
    vector<string> image;

    string line;
    while (true) {
        getline (input, line);
        image.push_back(line);
        if (input.eof()) {
            break;
   } 
   }

    vector<string> splitImage;
    for(int i = 0; i<image.size(); i++){
      split(image[i], " \t\n\r", splitImage); 
    }
    string valid;
    for(int i = 0; i<splitImage.size(); i++){
        valid += splitImage[i];
    }

   return valid;
}
int main(int argc, char *argv[]){
    string filename(argv[1]);    
    string valid = getData(filename);
    stack<string> mystack;

    vector<string> starters;
    starters.push_back("(");
    starters.push_back("{");
    starters.push_back("[");
    vector<string> closers;
    closers.push_back(")");
    closers.push_back("}");
    closers.push_back("]");

    for(int i = 0; i< valid.size(); i++){
        if(valid.substr(i,i+1)==starters[0] || valid.substr(i,i+1)==starters[1] || valid.substr(i,i+1)==starters[2]){
            mystack.push(valid.substr(i,i+1));        
        }
        
    }

        
  }