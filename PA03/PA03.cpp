#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::cout; using std::cerr;
using std::cin;
using std::endl; using std::string;
using std::ifstream; using std::vector;

using namespace std;


struct student{
    string fname;
    string lname;
    int grade;
    string lgrade;
};
void calculateGrade(vector<student> p){
  for(int i = 0; i< p.size(); i++){
    if(p[i].grade >= 90){
      p[i].lgrade = "A";
    }else if(p[i].grade >= 80 && p[i].grade < 90){
      p[i].lgrade = "B";
    }else if(p[i].grade >= 70 && p[i].grade < 80){
      p[i].lgrade = "C";
    }else if(p[i].grade >= 60 && p[i].grade < 70){
      p[i].lgrade = "D";
    }else{
      p[i].lgrade = "F";
    }
  }
}
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

vector<string> getData(string input_file){
        ifstream file(input_file);

    if (!file.is_open()) {
        cerr << "Could not open the file" << input_file << "'" << endl;
        exit(1);
    }
    vector<string> students;
    string line;
    while (true) {
        getline (file, line);
        students.push_back(line);
        if (file.eof()) {
            break;
   }
}
return students;
}

int main(int argc, char *argv[])
{
    string filename(argv[1]);
    ifstream input(filename);

    if (!input.is_open()) {
        cerr << "Could not open the file"
             << filename << "'" << endl;
        return EXIT_FAILURE;
    }
    vector<string> tokens;
    vector<string> studentss = getData(filename);
    vector<student> students;
    for( int i = 0; i < studentss.size();i++){
      split(studentss[i], " ", tokens);   
    }
    for(int i = 0; i<tokens.size(); i+= 3){
      student x;
      x.fname = tokens[i];
      x.lname = tokens[i+1];
      x.grade = stoi(tokens[i+2]); 
      students.push_back(x);
    }
    calculateGrade(students);
    
    cout << endl;
    input.close();

    return EXIT_SUCCESS;
}
