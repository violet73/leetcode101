#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> gen(int numRows) {
        vector<vector<int>> res;
        if(numRows == 1) {
            vector<int> nums;
            nums.push_back(1);
            res.push_back(nums);
            return res;
        }
        if(numRows == 2) {
            vector<int> nums1, nums2;
            nums1.push_back(1);
            nums2.push_back(1);
            nums2.push_back(1);
            res.push_back(nums1);
            res.push_back(nums2);
            return res;
        }
        res = gen(numRows - 1);
        vector<int> newVec;
        newVec.push_back(1);
        for(int i = 0;i<res[res.size() - 1].size()-1;i++) {
            newVec.push_back(res[res.size() - 1][i] + res[res.size() - 1][i+1]);
        }
        newVec.push_back(1);
        res.push_back(newVec);
        return res;
    }

    vector<vector<int>> generate(int numRows) {
        return gen(numRows);

    }
};

int main() {
    Solution s;
    vector<vector<int>> res = s.generate(5);
    for(auto r : res) {
        for(auto rr : r) {
            cout << rr << " ,";
        }
        cout << endl;
    }


    return 0;
}