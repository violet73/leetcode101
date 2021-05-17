#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 1e5, profit = 0;
        for(int i:prices) {
            if(buy > i) {
                buy = i;
            }
            if(buy < i) {
                profit += i - buy;
                buy = i;
            }
        }
        return profit;
    }
};

int main() {

    
    return 0;
}