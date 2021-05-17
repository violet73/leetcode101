#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        bool deleteOne = false;
        while(l < r) {
            if(s[l] == s[r]) {
                l++;
                r--;
            } else {
                if(!deleteOne) {
                    if(r - l == 1) {
                        return true;
                    }
                    deleteOne = true;
                } else {
                    return false;
                }
                if(s[l+1] == s[r] && s[l] != s[r-1]) {
                    l++;
                    continue;
                }
                if(s[l+1] != s[r] && s[l] == s[r-1]) {
                    r--;
                    continue;
                }
                // 随便走一边都行？X
                if(s[l+1] == s[r] && s[l] == s[r-1]) {
                    return validPalindrome(s.substr(l+1, r - l - 1)) || validPalindrome(s.substr(l, r - l - 1));
                }
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.validPalindrome("ebcbbececabbacecbbcbe") << endl;

    return 0;
}