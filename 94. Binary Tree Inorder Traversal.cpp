#include <iostream>
#include <vector>

using namespace  std;


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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res, tmp;
        if(root == nullptr) {
            return res;
        }
        if(root->left != nullptr) {
            res = inorderTraversal(root->left);
        }
        if(root != nullptr) {
            res.push_back(root->val);
        }
        if(root->right != nullptr) {
            tmp = inorderTraversal(root->right);
            res.insert(res.end(), tmp.begin(), tmp.end());
        }

        return res;
    }
};

int main() {
    Solution s;
    TreeNode* n1 = new TreeNode(2);
    TreeNode* n2 = new TreeNode(3);
    n1->left = n2;
    TreeNode* root = new TreeNode(1);
    root->right = n1;
    vector<int> res = s.inorderTraversal(root);

    for(auto r : res) {
        cout << r << " ";
    }

    return 0;
}