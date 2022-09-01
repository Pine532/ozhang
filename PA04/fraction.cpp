#include <iostream>
#include <fraction.h>
#include <string>

using namespace std;

// sytax is ClassName::ClassFunction

fraction :: fraction(int top, int den){
    num = top;
    this->den = den;
}

// accessor function called gettirs should have "const" in the name because they do not modify the object
int fraction :: getNum() const{
    return num;
}
int fraction :: getDen() const{
    return den;
}
ostream &operator << (ostream &stream, const fraction &other){
    stream<< other.num<<"/"<<other.den;
    return stream;
}

//overrides the plus operator 
// we have the fraction be cpnst because we couldnt change it
fraction fraction :: operator+(const fraction & other) const{
    int newNum;
    int newDen;
    if(den == other.den){
        newNum = num+other.num;
        return (fraction(newNum, den));        
    }else{
        newDen = den * other.den;
        newNum = (other.num * den) + (num * other.den);
        return(fraction(newNum, newDen));
    }
}
fraction fraction :: operator-(const fraction & other) const{
    int newNum;
    int newDen;
    if(den == other.den){
        newNum = num-other.num;
        return (fraction(newNum, den));        
    }else{
        newDen = den * other.den;
        newNum = (num * other.den) - (other.num * den);
        return(fraction(newNum, newDen));
    }  
}
fraction fraction :: operator*(const fraction & other) const{
    int newNum;
    int newDen;     
        newDen = den * other.den;
        newNum = num * other.num;
        return(fraction(newNum, newDen));    
}
fraction fraction :: operator/(const fraction & other) const{
    int newNum;
    int newDen;     
        newDen = num * other.den;
        newNum = den * other.num;
        return(fraction(newNum, newDen));    
}
bool fraction :: operator==(fraction & other){     
        if(num == other.num && den == other.den){
            return true;
        }else{
            return false;
        } 
}

