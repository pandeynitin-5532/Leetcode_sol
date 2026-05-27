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
    bool check(TreeNode* r,long long int min,long long int max){
    if(!r) return true;

    if(r->val<=min || r->val>=max)
        return false;

    return check(r->left,min,r->val) && check(r->right,r->val,max);
}
    bool isValidBST(TreeNode* root) {
        return check(root,LLONG_MIN,LLONG_MAX);
    }
};