#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int dfs(vector<vector<int>>& grid, vector<vector<int>>& mark, int i, int j) {
        int area = 1;
        mark[i][j] = 1;
        if(j - 1 >= 0 && mark[i][j-1] == 0 && grid[i][j-1] == 1) area += dfs(grid, mark, i, j-1);
        if(j + 1 < grid[i].size() && mark[i][j+1] == 0 && grid[i][j+1] == 1) area += dfs(grid, mark, i, j+1);
        if(i - 1 >= 0 && mark[i-1][j] == 0 && grid[i-1][j] == 1) area += dfs(grid, mark, i-1, j);
        if(i + 1 < grid.size() && mark[i+1][j] == 0 && grid[i+1][j] == 1) area += dfs(grid, mark, i+1, j);

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> mark;
        for(int i = 0; i < m ;i++) {
            vector<int> tmp(n, 0);
            mark.push_back(tmp);
        }
        for(int i = 0; i < m ;i++) {
            for(int j = 0; j < n ;j++) {
                if(mark[i][j] == 0) {
                    if(grid[i][j] == 1) {
                        int area = dfs(grid, mark, i, j);
                        if(area > maxArea) {
                            maxArea = area;
                        }
                    }
                }
            }
        }
        return maxArea;
    }
};

int main() {
    vector<vector<int>> grid;
    vector<int> tmp1(3, 0);
    vector<int> tmp2(3, 0);
    vector<int> tmp3(3, 0);
    grid.push_back(tmp1);
    grid.push_back(tmp2);
    grid.push_back(tmp3);
    Solution s;
    s.maxAreaOfIsland(grid);

    return 0;
}