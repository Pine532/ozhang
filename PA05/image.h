using namespace std; 
#include <vector>
#include <string>
class Image{
    public:
        Image(string header, int height, int width, int pixels);
        string getHeader() const;
        int getWidth() const;
        int getHeight() const;
        int getPixels() const;
        int getSmallest(vector<string> values);
        int getLargest(vector<string> values);
        double getAverage(vector<string> values);


    private:
        string header;
        int height;
        int width;
        int pixels;    
};