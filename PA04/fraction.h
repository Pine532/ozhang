using namespace std; 
class fraction{
    public: 
        fraction(int top, int bottom);
        int getNum() const;
        int getDen() const;
        friend ostream &operator << (ostream &stream, const fraction &other);
        fraction operator +(const fraction & other) const;
        fraction operator -(const fraction & other) const;
        fraction operator *(const fraction & other) const;
        fraction operator /(const fraction & other) const;
        bool operator==(fraction & other);

    
    private:
        int num;
        int den;
};