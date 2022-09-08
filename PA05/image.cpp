#include <iostream>
#include <string>
#include<Image.h>

using namespace std;

Image :: Image(string h, int hei, int w, int p){
    header = h;
    height = hei;
    width = w;
    pixels = p;
}
string Image :: getHeader() const{
    return header;
}
int Image :: getHeight() const{
    return height;
}
int Image :: getWidth() const{
    return width;
}
int Image :: getPixels() const{
    return pixels;
}
double Image :: getAverage(vector<string> values){
    int total;
    int count;
    for(int i = 4; i < values.size(); i+=){
        total += stoi(values[i]);
        count++;
    }
    return total/count;
}
int Image :: getSmallest(vector<string> values){
    int lowest = stoi(values[4]);
    for(int i = 4; i<values.size(); i++){
        if(stoi(values[i]<lowest)){
            lowest = stoi(values[i]);
        }
    }
    return lowest;
}
int Image :: getLargest(vector<string> values){
    int largest = stoi(values[4]);
    for(int i = 0; i<values.size(); i++){
        if(stoi(values[i])>largest){
            largest = stoi(values[i]);
        }
    }
    return largest;
}
