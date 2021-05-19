#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        vector<vector<int>> res;
        vector<int> tmp;
        for(int i = 0; i < nums.size() ;i++) {
            visited[i] = true;
            tmp.push_back(nums[i]);
            dfs(nums, visited, tmp, res);
            visited[i] = false;
            tmp.pop_back();
        }

        return res;
    }

    static void dfs(vector<int>& nums, vector<bool>& visited, vector<int> tmp, vector<vector<int>>& res) {
        if(tmp.size() == nums.size()) {
            res.push_back(tmp);
            return;
        }
        for(int i = 0; i < nums.size() ;i++) {
            if(!visited[i]) {
                visited[i] = true;
                tmp.push_back(nums[i]);
                dfs(nums, visited, tmp, res);
                visited[i] = false;
                tmp.pop_back();
            }
        }
        return;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    Solution s;
    s.permute(nums);

    return 0;
}