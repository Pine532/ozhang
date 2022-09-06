#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <fraction.h>
using namespace std;

int main(int argc, char *argv[]){
    fraction foo(3, 2); // note it is not fraction foo = new fraction (3, 2);
    cout<<foo.getNum()<<"/"<<foo.getDen()<<endl; 
    cout<<foo<<endl;
    fraction bar(1, 3);
    cout<<foo<< "+" << bar << " = " << foo+bar<<endl;
    cout<<foo<< "-" << bar << " = " << foo-bar<<endl;
    cout<<foo<< "*" << bar << " = " << foo*bar<<endl;
    cout<<foo<< "/" << bar << " = " << foo/bar<<endl;
    if(foo==bar){
    cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}