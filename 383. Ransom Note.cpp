#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> avail;
        for(auto c : magazine) {
            if(avail.find(c) == avail.end()) {
                avail.insert({c, 0});
            }
            avail[c]++;
        }

        for(auto c : ransomNote) {
            if(avail.find(c) == avail.end()) {
                return false;
            }
            if(--avail[c] == -1) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    cout << s.canConstruct("aa", "aab");

    return 0;
}