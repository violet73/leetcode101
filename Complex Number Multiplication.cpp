#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int real1 = stoi(num1.substr(0, num1.find('+')));
        int img1 = stoi(num1.substr(num1.find('+')+1, num1.find('i') - num1.find('+') - 1));

        string tmp = num2.substr(0, num2.find('+'));
        int real2 = stoi(num2.substr(0, num2.find('+')));
        int img2 = stoi(num2.substr(num2.find('+')+1, num2.find('i') - num2.find('+') - 1));

        int real = real1 * real2 - img1 * img2;
        int img = real1 * img2 + img1 * real2;

        string cnum = to_string(real) + "+" + to_string(img) + "i";

        return cnum;
    }
};

int main() {
    string num1("1+1i"), num2("-3+-98i");

    Solution s;

    cout << s.complexNumberMultiply(num1, num2) << endl;

    return 0;
}