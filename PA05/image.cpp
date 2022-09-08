#include <iostream>
#include <string>
#include<image.h>

using namespace std;

image :: image(string h, int hei, int w, int p){
    header = h;
    height = hei;
    width = w;
    pixels = p;
}
string image :: getHeader() const{
    return header;
}
int image :: getHeight() const{
    return height;
}
int image :: getWidth() const{
    return width;
}
int image :: getPixels() const{
    return pixels;
}
