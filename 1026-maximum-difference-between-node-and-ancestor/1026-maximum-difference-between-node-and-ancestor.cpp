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
    void util(TreeNode *root, int maxNode, int minNode, int& ans){
        if(!root)
            return;
        ans = max(ans, max(abs(maxNode-root->val), abs(minNode-root->val)));
        maxNode = max(maxNode, root->val);
        minNode = min(minNode, root->val);
        util(root->left, maxNode, minNode, ans);
        util(root->right, maxNode, minNode, ans);
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans=0;
        util(root, root->val, root->val, ans);
        return ans;
    }
};