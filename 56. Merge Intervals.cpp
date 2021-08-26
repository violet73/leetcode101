#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        if(a[0] < b[0]) return true;
        return false;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res;
        int x = intervals[0][0], y = intervals[0][1];
        for(auto a : intervals) {
            if(a[0] <= y) {
                y = y < a[1] ? a[1]:y;
            } else {
                vector<int> tmp;
                tmp.push_back(x);
                tmp.push_back(y);
                res.push_back(tmp);
                x = a[0];
                y = a[1];
            }
        }
        vector<int> tmp;
        tmp.push_back(x);
        tmp.push_back(y);
        res.push_back(tmp);
        return res;
    }
};

int main() {
    vector<vector<int>> intervals;
    vector<int> tmp1;
    tmp1.push_back(1);
    tmp1.push_back(4);
    vector<int> tmp2;
    tmp2.push_back(4);
    tmp2.push_back(5);
    intervals.push_back(tmp1);
    intervals.push_back(tmp2);

    Solution s;
    s.merge(intervals);

    return 0;
}