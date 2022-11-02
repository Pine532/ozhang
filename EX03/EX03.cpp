#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]){
    int x = 5;
    int* pointer1 = &x; //pointer 1 points to the address of x
    cout<<"x: "<<x<<endl;
    cout<<"pointer1: "<<pointer1<<endl;
    cout<<"pointer1 points to "<<*pointer1<<endl;
    int* pointer2 = pointer1;//pointer2 points to the address of x
    x = 3;
    cout<<"x: "<<x<<"\t pointer 1: "<<*pointer1<< "\t pointer 2: "<<*pointer2<<endl;
    *pointer1 = 20;
    cout<<"x: "<<x<<"\t pointer 1: "<<*pointer1<< "\t pointer 2: "<<*pointer2<<endl;
}