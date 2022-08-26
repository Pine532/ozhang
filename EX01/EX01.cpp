#include <iostream>
#include <vector>


using namespace std;

int main(int argc, char const *argv[]){
    //argc is the number of strings given to this program
    //argv is the array of strings
    cout<<"Hello, World"<<endl;
    /*
    This is a 
    Multi
    Line Comment
    */
   int x = 8;
   cout<<"The number x is "<<x<<endl;
   int y;
   cout<<"Please enter a number for y:" ;
   cin>>y;
   cout<<"Your number for Y is:"<<y<<endl;

   bool blah = true; // this can also be a number 
   // 0 is false
   // everything else is true
   //Note. it is bool not boolean
   // primitive data types are int, float, double, bool, and char
   if(blah){
    cout<<"This is true"<<endl;
   }
   else{
    cout<<"This is false"<<endl;
   }
   
   int a = 0;  //sometimes c++ does not treat "int a" as 0. You should initialize everything to something
   //cout<<a<<endl;


   //you can convert a double to a int without casting
   double b = 5.3;
   int c = b;

   cout<<"B is: "<<b<<"C Is: "<<c<<"A is "<<a<<endl;

   string name = "Owen Zhang";
   cout<<"Name:"<<name<<endl;
   //strings are the same as java besides the functions

   cout<<"You Gave: "<<argc<<" Arguments, and they are: "<<endl;
   for(int i = 0; i<argc; i++){
    cout<<argv[i]<<endl;
   } 


   //most of the time you will take command line arguments instead of cin
   // the thing above is an array. Never use arrays in C++
   // use vectors instead

   int daArray[] = {2, 4, 6, 8};
   cout<<"At position 4 there is "<<daArray[4]<<endl;
   // you are allowed to go past the array's bounds. Very Dangerous!
   // C++ does not do arror checking, k nor can you check for its size.
   // When you make an array, C++ allocates that amount of memory. End of story.

   // vectors are like ArrayLists
   vector<int> foo; // vector called foo
   foo.push_back(53);//adds a 53
   foo.push_back(50);
   foo.push_back(8);
   cout<<foo.at(0)<<endl;
   cout<<foo[0]<<endl;
   cout<<foo.size()<<endl;
   foo.pop_back();
   foo[0] = 2;  //sets 0th position to 2
   foo.erase(foo.begin()+1);//removes element at pos 1
   cout<<"The vectore is holding "<<endl;
   for(int i = 0; i<foo.size(); i++){
    cout<<foo[i]<<endl;
   }


    return 0; //it is convention to return 0 of the program ran successfully
}