// 单调栈
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<int> sIndex;
        sIndex.push(0);
        for(int i = 1; i < temperatures.size() ;i++) {
            while(!sIndex.empty() && temperatures[i] > temperatures[sIndex.top()]) {
                res[sIndex.top()] = i - sIndex.top();
                sIndex.pop();
            }
            sIndex.push(i);
        }
        return res;
    }
};

int main() {
    vector<int> temperatures{73,74,75,71,69,72,76,73};

    Solution s;
    s.dailyTemperatures(temperatures);


    return 0;
}