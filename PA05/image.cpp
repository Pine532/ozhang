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
