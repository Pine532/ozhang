using namespace std; 
class Image{
    public:
        Image(string header, int height, int width, int pixels);
        string getHeader() const;
        int getWidth() const;
        int getHeight() const;
        int getPixels() const;


    private:
        string header;
        int height;
        int width;
        int pixels;    
};