#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return halfSearch(nums, target, 0, nums.size() - 1);
    }

    vector<int> halfSearch(vector<int>& nums, int target, int left, int right) {
        int first = -1, last = -1;
        int l = left, r = right;
        int mid = (l + r) / 2;

        while(l <= r) {
            if(nums[mid] == target) {
                int res = halfSearch(nums, target, l, mid-1)[0];
                first = res == -1 ? mid:res;
                res = halfSearch(nums, target, mid+1, r)[1];
                last = res == -1 ? mid:res;
                break;
            }
            if(nums[mid] < target) {
                l = mid + 1;
                mid = (l + r) / 2;
            } else {
                r = mid - 1;
                mid = (l + r) / 2;
            }
        }
        return {first, last};
    }
};

int main() {
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(10);

    Solution s;
    s.searchRange(nums, 8);


    return 0;
}