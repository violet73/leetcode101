#include <iostream>
#include <vector>
#include <string>

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, res, "");
        return res;
    }

    static void dfs(TreeNode* root, vector<string>& res, string str) {
        if(root == NULL) {
            return;
        }
        str = str + "->" + to_string(root->val);
        if(root->left == NULL && root->right == NULL) {
            res.push_back(str.substr(2));
            return;
        }
        dfs(root->left, res, str);
        dfs(root->right, res, str);
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    // TreeNode *l1 = new TreeNode(2);
    // TreeNode *l2 = new TreeNode(3);
    // root->left = l1;
    // root->right = l2;
    // TreeNode *ll1 = new TreeNode(5);
    // l1->right = ll1;
    Solution s;
    vector<string> strs = s.binaryTreePaths(root);
    cout << strs[0];


    return 0;
}