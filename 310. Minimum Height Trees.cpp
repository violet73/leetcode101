#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n < 2) {
            return vector<int>{0};
        }
        // adj matrix
        vector<set<int>> adjMatrix(n, set<int>{});
        vector<int> adjNum(n, 0);
        for(int i = 0; i < edges.size() ;i++) {
            adjMatrix[edges[i][0]].insert(edges[i][1]);
            adjMatrix[edges[i][1]].insert(edges[i][0]);
            adjNum[edges[i][0]]++;
            adjNum[edges[i][1]]++;
        }

        queue<int> leaves;
        for(int i = 0; i < adjNum.size() ;i++) {
            if(adjNum[i] == 1) {
                leaves.push(i);
            }
        }
        int cnt = n;
        // find the centric nodes, no more than 2 in a tree!
        while(cnt > 2) {
            cnt -= leaves.size();
            queue<int> newLeaves;
            while(leaves.size() > 0) {
                int leave = leaves.front();
                leaves.pop();
                for(int i : adjMatrix[leave]) {
                    adjNum[i]--;
                    if(adjNum[i] == 1) {
                        newLeaves.push(i);
                    } 
                    adjMatrix[leave].erase(i);
                    adjMatrix[i].erase(leave);
                } 
            }
            leaves = newLeaves;
        }

        vector<int> res;
        while(leaves.size() > 0) {
            res.push_back(leaves.front());
            leaves.pop();
        }

        return res;
    }
};

int main() {
    int n = 4;
    vector<vector<int>> edges;
    edges.push_back({1, 0});
    edges.push_back({1, 2});
    edges.push_back({1, 3});

    Solution s;
    s.findMinHeightTrees(n, edges);

    return 0;
}