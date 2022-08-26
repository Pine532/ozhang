#include <iostream>
#include <vector>
using namespace std;

struct Table{
    int NumberOfLegs;
    bool sturdy;
};

void actuallyChangeThis(int &x){
    x = 3;
    cout<<x<<endl;
};
int timeTwo(int num);

int main(int argc, char const *argv[]){
    Table foo;
    foo.NumberOfLegs = 4;
    foo.sturdy = false;

    int y = 5;
    actuallyChangeThis(y);
    cout<<y<<endl;

    int a  = 4;
    a = timeTwo(a);
    cout<<a<<endl;
}

int timeTwo(int num){
    return num*2;
}