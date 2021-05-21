#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(int a, int b) {
        string string1 = to_string(a) + to_string(b);
        string string2 = to_string(b) + to_string(a);

        if(string1 > string2) {
            return true;
        }

        return false;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string ans = "";
        bool zeroHeader = true;
        for(int num:nums) {
            if(num != 0) {
                zeroHeader = false;
            }
            if(!zeroHeader) {
                ans += to_string(num);
            }
        }

        return ans.size() == 0 ? "0":ans;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(30);
    nums.push_back(34);
    nums.push_back(5);
    nums.push_back(9);

    Solution s;
    s.largestNumber(nums);

    return 0;
}