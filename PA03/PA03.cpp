#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
struct student{
    string fname;
    string lname;
    int grade;
    string lgrade;
};
void calculateGrade(vector<student> &p){
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
int highestScore(vector<student> l){
  int highest = 0;
  for(int i = 0; i< l.size(); i++){
    if(l[i].grade>highest){
      highest = l[i].grade;
    }
  }
  return highest;
}
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
ofstream writeData(string output_file, vector<student> w){
  ofstream output(output_file);
  for(int i = 0; i < w.size(); i++){
    output<<w[i].fname<<" "<<w[i].lname<<" "<<w[i].grade<<" "<<w[i].lgrade<<endl;
  }
  output.close();
  return output;
}

int main(int argc, char *argv[])
{
    string filename(argv[1]);
    ifstream input(filename);
    string myFile(argv[2]);
  
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
    writeData(myFile, students);
    cout<<highestScore(students);
    input.close();
    return EXIT_SUCCESS;
}