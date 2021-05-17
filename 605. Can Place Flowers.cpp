#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int maxNum = 0, len = flowerbed.size();
        if(len == 1 && flowerbed[0] == 0) {
            maxNum++;
            flowerbed[0] == 1;
        }
        for(int i = 0; i < len ;i++) {
            if(flowerbed[i] == 0) {
                if(i == 0 && len > 1) {
                    if(flowerbed[1] == 0) {
                        maxNum++;
                        flowerbed[0] = 1;
                    }
                    continue;
                }
                if(i == len-1 && len > 1) {
                    if(flowerbed[len-2] == 0) {
                        maxNum++;
                        flowerbed[len-1] = 1;
                    }
                    continue;
                }
                if(flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
                    maxNum++;
                    flowerbed[i] = 1;
                }
            }
        }
        if(maxNum >= n) {
            return true;
        }
        return false;
    }
};

int main() {
    vector<int> f;
    f.push_back(1);
    f.push_back(0);
    f.push_back(0);
    f.push_back(0);
    f.push_back(1);
    Solution s;
    cout << s.canPlaceFlowers(f, 1) << endl;

    return 0;
}