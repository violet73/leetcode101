#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> nodes;
        if(root == NULL) {
            return res;
        }
        nodes.push(root);
        while(!nodes.empty()) {
            queue<TreeNode*> tmp;
            while(!nodes.empty()) {
                if(nodes.front()->left != NULL) {
                    tmp.push(nodes.front()->left);
                }
                if(nodes.front()->right != NULL) {
                    tmp.push(nodes.front()->right);
                }
                if(nodes.size() == 1) {
                    res.push_back(nodes.front()->val);
                }
                nodes.pop();
            }
            nodes = tmp;
        }
        return res;
    }
};

int main() {


    return 0;
}