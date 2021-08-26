#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long ub = sqrt(c);
        long long db = 0;
        while(ub >= db) {
            long long sum = ub * ub + db * db;
            if(sum == c) {
                return true;
            }
            if(sum > c) {
                ub--;
                continue;
            }
            if(sum < c) {
                db++;
                continue;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    cout << s.judgeSquareSum(2147482647);

    return 0;
}