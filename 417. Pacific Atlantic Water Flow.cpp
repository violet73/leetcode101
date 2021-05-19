#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static void dfs(vector<vector<int>>& heights, vector<vector<bool>>& canReach, int i, int j) {
        canReach[i][j] = true;
        if(i - 1 >= 0 && canReach[i-1][j] == false && heights[i-1][j] >= heights[i][j]) dfs(heights, canReach, i-1, j);
        if(i + 1 < heights.size() && canReach[i+1][j] == false && heights[i+1][j] >= heights[i][j]) dfs(heights, canReach, i+1, j);
        if(j - 1 >= 0 && canReach[i][j-1] == false && heights[i][j-1] >= heights[i][j]) dfs(heights, canReach, i, j-1);
        if(j + 1 < heights[0].size() && canReach[i][j+1] == false && heights[i][j+1] >= heights[i][j]) dfs(heights, canReach, i, j+1);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        // 反向考虑，从edges往上流，所能到达的地方即为可以流入ocean的
        vector<vector<bool>> canReachP(m, vector<bool>(n, false));
        vector<vector<bool>> canReachA(m, vector<bool>(n, false));
        // top&bottom
        for(int i = 0; i < n ;i++) {
            dfs(heights, canReachA, m-1, i);
            dfs(heights, canReachP, 0, i);
        }
        // left&right
        for(int i = 0; i < m ;i++) {
            dfs(heights, canReachA, i, n-1);
            dfs(heights, canReachP, i, 0);
        }
        // find both true
        vector<vector<int>> res;
        for(int i = 0; i < m ;i++) {
            for(int j = 0; j < n ;j++) {
                if(canReachA[i][j] && canReachP[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};

int main() {


    return 0;
}