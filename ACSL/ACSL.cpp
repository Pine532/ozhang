#include <bits/stdc++.h>
#include<cmath>


using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'countLargestDigit' function below.
 *]
 
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER num
 *  2. INTEGER base
 *  3. INTEGER start
 */

int countLargestDigit(int num, int base, long int start) {
    vector<int> values;
    long long int temp = start;
    int largest = base;
    vector<int> starting;
    while (temp > 0){
        long int digit = temp % 10;
        temp /= 10;
        starting.push_back(digit);
    }
    temp = 0;
    for(int i = 0;i<starting.size(); i++){
        temp += starting[i]*(pow(largest,i));
    }    
    int temp1 = temp;
    int temp2 = temp;
    int track = num;
    string x = "";
    while(track > 0){
        while(temp1>0){
            x = to_string(temp1%largest) + x;
            temp1/=largest;            
        }
        values.push_back(stoll(x));
        x = "";
        track--;
        temp2++;
        temp1 = temp2;
        }
        for(int i =0; i<values.size(); i++){
            cout<<values[i]<<endl;
        }
        int tracker=0;
        long long int temporary = 0;
        for(int i = 0; i<values.size(); i++){
            temporary = values[i];
            vector<int> nums;
            while (temporary > 0){
                int digit = temporary % 10;
                temporary /= 10;
                nums.push_back(digit);
            for(int k = 0; k < nums.size(); k++){
                if(nums[k] == largest-1){
                    tracker++;
                }
            }
            nums.clear();
            }
            
        }
        return tracker;
    }

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string num_temp;
    getline(cin, num_temp);

    int num = stoi(ltrim(rtrim(num_temp)));

    string base_temp;
    getline(cin, base_temp);

    int base = stoi(ltrim(rtrim(base_temp)));

    string start_temp;
    getline(cin, start_temp);

    int start = stoi(ltrim(rtrim(start_temp)));

    int result = countLargestDigit(num, base, start);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
