#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1, target = nums.size() - k, mid;
        while (true) {
            int mid = quickSelection(nums, l, r);
            if(mid == target) {
                return nums[mid];
            }
            if(mid < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return nums[l];
    }

    static int quickSelection(vector<int>& nums, int l, int r) {
        // l is the pivot
        int i = l + 1, j = r;
        while(true) {
            while(i <= r && nums[i] <= nums[l]) {
                i++;
            }
            while(j > l && nums[j] >= nums[l]) {
                j--;
            }
            if(j <= i) {
                break;
            }
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
        int tmp = nums[l];
        nums[l] = nums[j];
        nums[j] = tmp;

        return j;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(4);
    Solution s;

    cout << s.findKthLargest(nums, 2) << endl;

    return 0;
}