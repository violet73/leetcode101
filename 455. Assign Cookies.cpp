#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int num = 0;
        int pre_index = 0;
        for(int i = 0; i < s.size() ; i++) {
            if(s[i] >= g[pre_index]) {
                num++;
                pre_index++;
            }
            if(pre_index >= g.size()) {
                break;
            }
        }
        return num;
    }
};

int main() {
    vector<int> g,s;
    g.push_back(1);
    g.push_back(2);
    g.push_back(3);
    s.push_back(1);
    s.push_back(1);

    Solution son;
    cout << son.findContentChildren(g, s) << endl;
    return 0;
}