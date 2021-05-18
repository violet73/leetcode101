#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int maxEqualLen = 0;
        string maxDictStr = "";
        for(string &i:dictionary) {
            int l = 0, r = 0, cnt = 0;
            while(l < s.size() && r < i.size()) {
                if(s[l++] == i[r]) {
                    r++;
                    cnt++;
                }
            }
            if(cnt == i.size()) {
                if(i.size() > maxEqualLen || (i.size() == maxEqualLen && i < maxDictStr)) {
                    maxEqualLen = i.size();
                    maxDictStr = i;
                }
            }
        }
        return maxDictStr;
    }
};

int main() {
    Solution s;
    vector<string> dict;
    dict.push_back("ale");
    // dict.push_back("b");
    // dict.push_back("c");
    dict.push_back("apple");
    dict.push_back("monkey");
    dict.push_back("plea");

    cout << s.findLongestWord("abpcplea", dict) << endl;

    return 0;
}
