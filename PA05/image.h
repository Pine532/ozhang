using namespace std; 
#include <vector>
#include <string>
class Image{
    public:
        Image(string header, int height, int width, int pixel);
        string getHeader() const;
        int getWidth() const;
        int getHeight() const;
        int getPixel() const;
        int getSmallest(vector<string> values);
        int getLargest(vector<string> values);
        double getAverage(vector<string> values);
        vector<string> removeComment(vector<string> values);


    private:
        string header;
        int height;
        int width;
        int pixel;    
};