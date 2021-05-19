#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int num = 0;
        int visit[isConnected.size()];
        for(int i = 0; i < isConnected.size() ;i++) {
            visit[i] = 0;
        }
        queue<int> bfsQueue;
        for(int i = 0; i < isConnected.size() ;i++) {
            if(visit[i] == 0) {
                num++;
                bfsQueue.push(0);
                visit[0] = 1;
            }
            while(!bfsQueue.empty()) {
                int index = bfsQueue.front();
                bfsQueue.pop();
                for(int j = 0; j < isConnected.size() ;j++) {
                    if(isConnected[index][j] == 1 && visit[j] == 0) {
                        visit[j] = 1;
                        bfsQueue.push(j);
                    }
                }
            }
        }
        return num;
    }
};

int main() {



    return 0;
}