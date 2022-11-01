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
bool checkMail(vector<person> a, person x){
    for(int k = 0; k<a.size(); k++){
                if(a[k].mail.compare(x.mail) == 0){
                    cerr<<"same person cannot be entered twice"<<endl;
                    return false;
                }
            }
            return true;
}
vector<person> updatePos(vector<person> a){
    for(int i = 0; i<a.size(); i++){
        a[i].pos = i;
    }
    return a;
}

int main(int argc, char *argv[])
{
    string myFile(argv[1]);
    vector<person> people;
    int c;
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
            if(checkMail(people, x) == true){
                people.push_back(x);
                people = updatePos(people);
            }else{
                continue;
            }
            writeData(myFile, people);
        }
        if(c == 2){
            people.erase(people.begin());
            people = updatePos(people);
            writeData(myFile, people);
        }if(c == 3){
            people.clear();
            writeData(myFile, people);
        }if(c == 4){
            cout << "queue created"<<endl;
            break;
        }
    }
}