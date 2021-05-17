#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int> & a, vector<int> & b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 按最小右边界进行排序，移除数 = 总数 - 最大不重叠数
        sort(intervals.begin(), intervals.end(), cmp);
        int maxNonOverlapNum = 0, minRight = intervals[0][0];
        for(int i = 0; i < intervals.size(); i++) {
            if(intervals[i][0] >= minRight) {
                maxNonOverlapNum++;
                minRight = intervals[i][1];
            }
        }
        return intervals.size() - maxNonOverlapNum;
    }
};

int main() {


    return 0;
}