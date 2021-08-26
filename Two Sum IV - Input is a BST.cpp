// two sum : always turn to find (target - val)
// using set to store pre val.
#include <iostream>
#include <set>

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
    static bool findSub(set<int> &pre, TreeNode *node, int k) {
        if(node == nullptr) return false;
        if(pre.find(k - node->val) != pre.end()) {
            return true;
        }
        pre.insert(node->val);
        return findSub(pre, node->left, k) || findSub(pre, node->right, k);
    }

    bool findTarget(TreeNode* root, int k) {
        set<int> pre;
        return findSub(pre, root, k);
    }
};

int main() {



    return 0;
}