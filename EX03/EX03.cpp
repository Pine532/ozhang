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

    int y = 9;
    *pointer1 = y;
    y = 5;
    cout<<"x: "<<x<<"\t pointer 1: "<<*pointer1<< "\t pointer 2: "<<*pointer2<<endl;
    pointer1 = &y;
    y = 16;
    cout<<"x: "<<x<<"\t pointer 1: "<<*pointer1<< "\t pointer 2: "<<*pointer2<<endl;

/*
    // up until this pointer, you had to define the size of the array before time..
    int arraySize;
    cout<<"enter the size of the array"<<endl;
    cin>>arraySize;
    int *arr = new int[arraySize]; // the pointer is on the stack while the actual array is on the heap.
    //This is exactly what a vector is
    for(int i = 0 ; i<arraySize; i++){
        *(arr + i) = i;
        //both are the same thing
    }
    cout<< "3rd Element: " << *(arr+3) << " OR " <<arr[3] <<endl; //these are the same thing
    delete[] arr; //delete arr will not invoke a class's destructor on each element.
    //If you use brackets with new, you much use delete with brackets
    arr = NULL; //you MUST use the value to null to prevent disastrous unintended bahavior
    if(arr)
    {
        //This would pass if the pointer is not set to null.
        //arr[0] = 3;//you have NO IDEA what this is changing
        cout<<arr[0]<<endl;
        //1. prevent double delete
        //2. Prevent editing unknown values
    }
    int* pointer3 = new int(3); // you put the int on the heapp. the pointer is on the stack
    delete pointer3; //you MUST delete the pointer
    pointer3 = NULL;
    int* pointer4 = new int(4);
    int* pointer5 = pointer4;
    delete pointer4;
    delete pointer5;//this pointer is already deleted you just double deleted
    return 0;
*/
char ch, &rch = ch, *pch = &ch;
int m = 8, &rm = m, x = 2, &rx = x;
rm = rx;


}