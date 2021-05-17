#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }

    vector<int> partitionLabels(string s) {
        vector<vector<int>> charFirstAndLatst;
        for(int i = 0; i < 26 ;i++) {
            charFirstAndLatst.push_back({-1,-1});
        }
        // 记录某个单词最早出现位置以及最后出现位置，对最早出现位置进行升序排序，然后进行区间合并，区间有重叠的才合并（贪心）
        for(int i = 0; i < s.size() ;i++) {
            if(charFirstAndLatst[s[i]-'a'][0] == -1) {
                charFirstAndLatst[s[i]-'a'][0] = i;
            }
            charFirstAndLatst[s[i]-'a'][1] = i;
        }
        sort(charFirstAndLatst.begin(), charFirstAndLatst.end(), cmp);
        vector<vector<int>> merged;
        int left, right;
        for(int i = 0; i < charFirstAndLatst.size() ;i++) {
            if(charFirstAndLatst[i][0] == -1) {
                continue;
            } else {
                left = charFirstAndLatst[i][0];
                right = charFirstAndLatst[i][1];
                break;
            }
        }
        for(int i = 0; i < charFirstAndLatst.size() ;i++) {
            if(charFirstAndLatst[i][0] == -1) {
                continue;
            }
            if(charFirstAndLatst[i][0] <= right) {
                right = (right < charFirstAndLatst[i][1]) ? charFirstAndLatst[i][1]:right;
            }  else {
                merged.push_back({left, right});
                left = charFirstAndLatst[i][0];
                right = charFirstAndLatst[i][1];
            }
        }
        vector<int> res;
        for(vector<int> &i:merged) {
            res.push_back(i[1] - i[0] + 1);
        }
        res.push_back(right - left + 1);
        return res;
    }
};

int main() {
    string str = "caedbdedda";
    Solution s;
    s.partitionLabels(str);

    return 0;
}