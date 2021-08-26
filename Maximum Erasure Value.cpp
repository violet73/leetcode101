#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0, r = 0, maxValue = 0, sum = 0;
        set<int> inSet;
        while(l <= r && r < nums.size()) {
            if(inSet.find(nums[r]) == inSet.end()) {
                inSet.insert(nums[r]);
                sum += nums[r];
                if(sum > maxValue) {
                    maxValue  = sum;
                }
                r++;
            } else {
                sum -= nums[l];
                inSet.erase(nums[l]);
                l++;
            }
        }
        return maxValue;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);

    Solution s;

    cout << s.maximumUniqueSubarray(nums) << endl;

    return 0;
}