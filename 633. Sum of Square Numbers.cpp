#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        int maxRight = sqrt(c);
        long long l = 0, r = 0;
        while(true) {
            if(l * l + r * r < c) {
                r ++;
            } else {
                if(l * l + r * r == c) {
                    return true;
                } else {
                    l ++;
                    r --;
                    if(l > r) {
                        return false;
                    }
                }
            }
        }
    }
};

int main() {
    Solution s;
    cout << s.judgeSquareSum(2147482647) << endl;

    return 0;
}