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
    void util(TreeNode* root, int targetSum, vector<vector<int>>& ans,
              vector<int> path, int sum){
        if(!root)
            return;
        path.push_back(root->val);
        sum+=root->val;
        if(!root->left&&!root->right){
            if(sum==targetSum){
                ans.push_back(path);
            }
            return;
        }
        util(root->left, targetSum, ans, path, sum);
        util(root->right, targetSum, ans, path, sum);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        util(root, targetSum, ans, temp, sum);
        return ans;
    }
};