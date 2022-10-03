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


int main(int argc, char *argv[]){
    string hi = argv[1];
    vector<string> split1;
    split(hi, " ", split1);  
    for(int i = 0; i<split1.size(); i++){
        cout<<stoi(split1[i])*2.54<<endl;
    }
}