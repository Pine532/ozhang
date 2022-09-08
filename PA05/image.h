using namespace std; 
class Image{
    public:
        Image(string header, int height, int width, int pixels);
        string getHeader() const;
        int getWidth() const;
        int getHeight() const;
        int getPixels() const;
        int getSmallest() const;
        int getLargest() const;
        double getAverage() const;


    private:
        string header;
        int height;
        int width;
        int pixels;    
};