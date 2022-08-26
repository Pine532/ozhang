#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::cout; using std::cerr;
using std::cin;
using std::endl; using std::string;
using std::ifstream; using std::vector;
using namespace std;

int main(int argc, char *argv[]){
{
    string filename(argv[1]);
    vector<int> numbers;
    int number;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file"
             << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    while (input_file >> number) {
        numbers.push_back(number);
    }
    int x = 0;
    int y = 0;

      while (x <= 9){
        for (int i = 0; i < numbers.size(); i++) {
          if(numbers[i] == x){
            y++;
          }
          }
          cout << x << " " << y <<endl;
          x++;
          y = 0;
      } 
    
    cout << endl;
    input_file.close();

    return EXIT_SUCCESS;
}
}