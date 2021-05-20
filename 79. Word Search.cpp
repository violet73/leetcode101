#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size() ;i++) {
            for(int j = 0; j < board[0].size() ;j++) {
                if(board[i][j] == word[0]) {
                    vector<vector<bool>> mark(board.size(), vector<bool>(board[0].size(), false));
                    if(dfs(board, mark, word, 0, i, j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    static bool dfs(vector<vector<char>>& board, vector<vector<bool>>& mark, string& word, int cnt, int i, int j) {
        mark[i][j] = true;
        if(cnt == word.size()-1 && board[i][j] == word[cnt]) {
            return true;
        }
        if(board[i][j] != word[cnt]) {
            return false;
        }
        bool res = false;
        if(j - 1 >= 0 && mark[i][j-1] == 0) {
            res = res || dfs(board, mark, word, cnt+1, i, j-1);
            mark[i][j-1] = false;
        }
        if(j + 1 < board[i].size() && mark[i][j+1] == 0) {
            res = res || dfs(board, mark, word, cnt+1, i, j+1);
            mark[i][j+1] = false;
        }
        if(i - 1 >= 0 && mark[i-1][j] == 0) {
            res = res || dfs(board, mark, word, cnt+1, i-1, j);
            mark[i-1][j] = false;
        }
        if(i + 1 < board.size() && mark[i+1][j] == 0) {
            res = res || dfs(board, mark, word, cnt+1, i+1, j);
            mark[i+1][j] = false;
        }
        return res;
    }
};

int main() {
    vector<vector<char>> board;
    vector<char> tmp1;
    tmp1.push_back('A');
    tmp1.push_back('B');
    tmp1.push_back('C');
    tmp1.push_back('E');

    vector<char> tmp2;
    tmp2.push_back('S');
    tmp2.push_back('F');
    tmp2.push_back('C');
    tmp2.push_back('S');

    vector<char> tmp3;
    tmp3.push_back('A');
    tmp3.push_back('D');
    tmp3.push_back('E');
    tmp3.push_back('E');

    board.push_back(tmp1);
    board.push_back(tmp2);
    board.push_back(tmp3);

    Solution s;
    cout << s.exist(board, "z") << endl;

    return 0;
}