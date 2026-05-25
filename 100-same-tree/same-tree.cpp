/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
      void preorder(TreeNode* root, vector<int>& ans) {
    if (!root) {
        ans.push_back(INT_MIN);
        return;
    }
    ans.push_back(root->val);  
    preorder(root->left, ans);
    preorder(root->right, ans);
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    vector<int> ans, ans1;
    preorder(p, ans);
    preorder(q, ans1);
    return ans == ans1;
}
};