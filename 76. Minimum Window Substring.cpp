#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // 统计每个缺少字符的所需数量以及是否某字符已经满足数量
        vector<int> LackedCharsNum(128, 0);
        vector<bool> charsEnoughFlg(128, false);
        for(char i:t) {
            LackedCharsNum[i] ++;
            charsEnoughFlg[i] = true;
        }
        // 当cnt == t.size()，表示窗口已满足条件
        int cnt = 0, l = 0, minLeft = 0, minSize = s.size();
        bool enoughFlg = false;
        for(int r = 0; r < s.size() ;r++) {
            // 若s[r]是t中的字符
            if(charsEnoughFlg[s[r]]) {
                if(LackedCharsNum[s[r]]-- > 0) {
                    cnt ++;
                }
                // 尝试在条件满足的情况下，l往后移，贪心缩小
                while(cnt == t.size()) {
                    enoughFlg = true;
                    if(charsEnoughFlg[s[l]] && LackedCharsNum[s[l]] == 0) {
                        cnt -- ;
                    }
                    LackedCharsNum[s[l]] ++;
                    if(r - l + 1 < minSize) {
                        minLeft = l;
                        minSize = r - l + 1;
                    }
                    l++;
                }
            }
        }
        return enoughFlg ? s.substr(minLeft, minSize):"";
    }
};

int main() {
    Solution s;
    cout << s.minWindow("ab", "a") << endl;

    return 0;
}