#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
struct person
{
    string fname;
    string lname;
    string mail;
    int pos;
};
void split(const string &str, const string &delim, vector<string> &parts)
{
    size_t start, end = 0;
    while (end < str.size())
    {
        start = end;
        while (start < str.size() && (delim.find(str[start]) != string::npos))
        {
            start++; // skip initial whitespace
        }
        end = start;
        while (end < str.size() && (delim.find(str[end]) == string::npos))
        {
            end++; // skip to end of word
        }
        if (end - start != 0)
        { // just ignore zero-length strings.
            parts.push_back(string(str, start, end - start));
        }
    }
}

void writeData(string output_file, vector<person> w)
{
    ofstream output(output_file);
    output<<"<html>"<<endl<<"<body>"<<endl<<"<table>"<<"<tbody>"<<endl;
    for (int i = 0; i < w.size(); i++)
    {
        output <<"<tr>"<<endl<<"<td>"<< w[i].pos << "</td>"<<endl<< "<td>"<< w[i].fname << " " << w[i].lname <<"</td>"<<endl<<"</tr>"<<endl;
    }
    output<<"</tbody>"<<endl<<"</table>"<<endl<<"</body>"<<"</html>"<<endl;
    output.close();
}

int main(int argc, char *argv[])
{
    string myFile(argv[1]);
    vector<person> people;
    int c;
    int i = 0;
    while (true){
        cout<<"1) Raise Hand"<<endl;
        cout<<"2) Remove Head"<<endl;
        cout<<"3) Clear queue"<<endl;
        cout<<"4) Exit Program"<<endl;
        cout<<"Choice (enter a number):";
        cin>>c;
        if(c == 1){
            person x;
            cout << "First Name:";
            cin >> x.fname;
            cout << "Last Name:";
            cin >> x.lname;
            cout << "Email:";
            cin >> x.mail;
            x.pos = i;
            i++;
            people.push_back(x);
        }
        if(c == 2){
            people.pop_back();
        }if(c == 3){
            people.clear();
        }if(c == 4){
            cout << "queue created"<<endl;
            break;
        }
    }
    writeData(myFile, people);
}


