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
    int sum=0;
    void util(TreeNode* root, int depth, int& max_depth){
        if(!root)
            return;
        // cout<<root->val<<" "<<depth<<" "<<max_depth<< "     ";
        if(!root->left&&!root->right){
            if(depth>max_depth)
                sum = root->val;
            else if(depth==max_depth)
                sum+=root->val;
            max_depth= max(depth, max_depth);
            return;
        }
        
        util(root->left, depth+1,max_depth);
        util(root->right, depth+1, max_depth);
    }
    int deepestLeavesSum(TreeNode* root) {
        int md = 0;
        util(root, 0, md);
        return sum;
    }
};