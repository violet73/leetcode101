#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        // 1.初始化所有为1
        vector<int> candy;
        for(int i = 0;i < ratings.size() ;i++) {
            candy.push_back(1);
        }
        // 2.从左到右，若右边比当前rating高，更新右边糖果为当前+1
        for(int i = 0;i < candy.size() - 1 ;i++) {
            if(ratings[i] < ratings[i+1]) {
                candy[i+1] = candy[i] + 1;
            }
        }
        // 3.从右到左，若左边比当前rating高且左边糖果数不大于当前糖果数，更新左边糖果为当前+1
        for(int i = candy.size() - 1;i > 0 ;i--) {
            if(candy[i-1] <= candy[i] && ratings[i] < ratings[i-1]) {
                candy[i-1] = candy[i] + 1;
            }
        }
        int sum = 0;
        for(int i = 0;i < candy.size() ;i++) {
            sum += candy[i];
        }
        return sum;
    }
};

int main() {
    vector<int> ratings;
    ratings.push_back(1);
    ratings.push_back(0);
    ratings.push_back(1);

    Solution s;
    cout << s.candy(ratings) << endl;

    return 0;
}