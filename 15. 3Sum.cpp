#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 3) return ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() ;i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i + 1, right = nums.size() - 1;
            while(left < right) {
                if(right < nums.size() - 1 && nums[right] == nums[right + 1]) {
                    right--;
                    continue;
                }
                if(nums[left] + nums[right] + nums[i] == 0) {
                    ans.push_back({nums[left], nums[right], nums[i]});
                    left++;
                    right--;
                    continue;
                }
                if(nums[left] + nums[right] < -nums[i]) {
                    left++;
                    continue;
                }
                if(nums[left] + nums[right] > -nums[i]) {
                    right--;
                    continue;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums{-2,0,0,2,2};

    Solution s;

    s.threeSum(nums);


    return 0;
}