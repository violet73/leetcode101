#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool checkZeroOnes(string s) {
        int maxOneLen = 0, maxZeroLen = 0;
        int tmpOneLen = 0, tmpZeroLen = 0;

        for(char c : s) {
            if(c == '1') {
                if(tmpZeroLen > maxZeroLen) {
                    maxZeroLen = tmpZeroLen;
                }
                tmpZeroLen = 0;
                tmpOneLen ++;
            } else {
                if(tmpOneLen > maxOneLen) {
                    maxOneLen = tmpOneLen;
                }
                tmpOneLen = 0;
                tmpZeroLen ++;
            }
        }

        return (maxOneLen > maxZeroLen);
    }
};

int main() {



    return 0;
}