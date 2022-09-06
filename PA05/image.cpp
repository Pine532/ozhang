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
