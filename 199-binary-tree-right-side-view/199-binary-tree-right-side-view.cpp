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
    
    void helper(TreeNode* root, int depth, vector<int> &ans){
        if(!root)
            return;
        if(ans[depth]==-1)
            ans[depth]= root->val;
        helper(root->right, depth+1, ans);
        helper(root->left, depth+1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(101, -1);
        helper(root, 0, ans);
        for(int i=100;i>=0;i--){
            if(ans[i]==-1)
                ans.pop_back();
        }
        return ans;
    }
};