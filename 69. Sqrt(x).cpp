#include <iostream>

#define ll long long

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int l = 1, r = x;
        ll mid = (l + r) / 2;
        while(l <= r) {
            if(mid * mid <= x && (mid+1) * (mid+1) > x) {
                return mid;
            }
            if(mid * mid < x) {
                l = mid;
                mid = (l + r) / 2;
            } else {
                r = mid;
                mid = (l + r) / 2;
            }
        }
        return 0;
    }
};

int main() {
    Solution s;

    cout << s.mySqrt(2147483647) << endl;

    return 0;
}