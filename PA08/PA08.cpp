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
    person *next = NULL;
    int pos;
};
void writeData(string output_file, person *head)
{
    
    person *something = head;
    ofstream output(output_file);
    output<<"<html>"<<endl<<"<body>"<<endl<<"<table>"<<"<tbody>"<<endl;
    int i = 1;
    while(something->next != NULL)
    {
        output <<"<tr>"<<endl<<"<td>"<< i << "</td>"<<endl<< "<td>"<< something->fname << " " << something->lname <<"</td>"<<endl<<"</tr>"<<endl;
        something = something-> next;
        i++;
    }
    output<<"</tbody>"<<endl<<"</table>"<<endl<<"</body>"<<"</html>"<<endl;
    output.close();
}
bool checkMail(person *x, person *last){
    person *something = x;
    while(something->next != NULL){
                if(last->mail.compare(x->mail) == 0){
                    cerr<<"same person cannot be entered twice"<<endl;
                    return false;
                }
                something = something->next;
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
    person *head = NULL;
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
            person *temp = new person;
            person *something = head;
            if(head == NULL){
                cout << "First Name:";
                cin >> temp->fname;
                cout << "Last Name:";
                cin >> temp->lname;
                cout << "Email:";
                cin >> temp->mail;
                head = temp;
                writeData(myFile, head);
            }
            else{
                person *last = new person;
                cout << "First Name:";
                cin >> last->fname;
                cout << "Last Name:";
                cin >> last->lname;
                cout << "Email:";
                cin >> last->mail;
                if(checkMail(head, last) == true){
                    while(something->next != NULL){
                        something = something->next;
                    }
                something->next = last;
                writeData(myFile, head);
                delete last;

                }else{
                continue;
                }
            }
            writeData(myFile, head);
        }if(c == 2){
        }if(c == 3){
        }if(c == 4){
            cout << "queue created"<<endl;
            break;
        }
    }
}