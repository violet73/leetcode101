#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // static void dfs(int row, int col, vector<vector<int>>& matrix) {
    //     if(row == 0) {
    //         for(int i = 1;i < matrix[0].size();i++) {
    //             if(col == 0 && matrix[i][col] == 0) {
    //                 dfs(i, col, matrix);
    //             } else {
    //                 matrix[i][col] = 0;
    //             }
    //         }
    //     }
    //     if(col == 0) {
    //         for(int i = 1;i < matrix.size();i++) {
    //             if(row == 0 && matrix[row][i] == 0) {
    //                 dfs(row, i, matrix);
    //             } else {
    //                 matrix[row][i] = 0;
    //             }
    //         }
    //     }
    // }

    [
        [1,2,3,4],
        [5,0,7,8],
        [0,10,11,12],
        [13,14,15,0]
    ]

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }   
        }

        for(int i = 1;i < n;i++) {
            if(matrix[i][0] == 0) {
                for(int j = 0;j < m;j++) {
                    matrix[i][j] = 0;
                }   
            }   
        }

        for(int j = 1;j < m;j++) {
            if(matrix[0][j] == 0) {
                for(int i = 0;i < n;i++) {
                    matrix[i][j] = 0;
                }   
            }   
        }

        if(matrix[0][0] == 0) {
            for(int j = 1;j < m;j++) {
                matrix[0][j] = 0;
            }
            for(int i = 1;i < n;i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {


    return 0;
}