#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n == 0) {
            return 0;
        }
        vector<bool> shai(n+1, true);
        if(n+1 > 1) {
            shai[1] = false;
        }
        if(n+1 > 2) {
            shai[2] = true;   
        }

        for(int i = 2; i < n ;i++) {
            for(int j = i * 2; j <= n ;j+=i) {
                shai[j] = false;
            }
        }
        int res = 0;
        for(int i = 2; i < n ;i++) {
            if(shai[i]) {
                res ++;
            }
        }

        return res;
    }
};

int main() {
    


    return 0;
}