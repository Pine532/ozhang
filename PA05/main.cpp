#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Image.h>
#include <stdexcept>

using namespace std; 
const bool debug = false;

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

vector<string> getData(string file){
 ifstream input(file);
  
    if (!input.is_open()) {
        cerr << "Could not open the file"
             << file << "'" << endl;
        exit(1);
    }
    vector<string> image;
    string line;
    getline(input, line);
    if(line.find(" ") != string::npos){
          line.erase(line.find(" "), line.length());
        }
      if(!(line=="P2")){
        exit(1);
    }
    image.push_back(line);
    while (true) {
        getline (input, line);
        if(line.find("#") != string::npos){
          line.erase(line.find("#"), line.length());
        }
        image.push_back(line);
        if (input.eof()) {
            break;
   } 
   }

    vector<string> splitImage;
    for(int i = 0; i<image.size(); i++){
      split(image[i], " \t\n\r", splitImage); 
    }
   return splitImage;
}

int main(int argc, char *argv[]){
    string filename(argv[1]);
    
    vector<string> splitImage1 = getData(filename);  
    
    
    Image foo(splitImage1[0], stoi(splitImage1[2]), stoi(splitImage1[1]), stoi(splitImage1[3]));
    vector<string> splitImage = foo.removeComment(splitImage1);
    if(foo.getPixel()>255){
      exit(1);
    }
    if(foo.getPixel()<0){
      exit(1);
    }
    try{
    for(int i = 4; i<splitImage.size(); i++){
      stoi(splitImage[i]);
    }
    }catch(std::invalid_argument){
      exit(1);
    }

    if((foo.getHeight()<=0)||(foo.getWidth()<=0)){
      exit(1);
    }
  
    if(!(((foo.getHeight()*foo.getWidth())) == (splitImage.size()-4))){
      exit(1);
    }
    
    for(int i = 4; i < splitImage.size(); i++){
      if(stoi(splitImage[i]) > foo.getPixel()){
        exit(1);  
      }
      if(stoi(splitImage[i]) < 0){
        exit(1);
      }
    }

    cout<<foo.getSmallest(splitImage)<< " "<<foo.getAverage(splitImage)<< " " <<foo.getLargest(splitImage);
  }