#include <iostream>
#include <vector>

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
    // inOrder traverse is strictly asending.
    bool isValidBST(TreeNode* root) {
        vector<int> inOrderList;
        inOrder(root, inOrderList);
        for(int i = 0; i < inOrderList.size() - 1 ;i++) {
            if(inOrderList[i] >= inOrderList[i+1]) {
                return false;
            }
        }
        return true;
    }

    static void inOrder(TreeNode* root, vector<int>& inOrderList) {
        if(root == NULL) return;
        inOrder(root->left, inOrderList);
        inOrderList.push_back(root->val);
        inOrder(root->right, inOrderList);
    }
};

int main() {


    return 0;
}