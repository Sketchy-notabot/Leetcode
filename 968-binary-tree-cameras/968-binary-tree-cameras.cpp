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
    int ans;
    set<TreeNode*> covered;
public:
    void util(TreeNode* curr, TreeNode* parent){
        if(!curr) return;
        util(curr->left, curr);
        util(curr->right, curr);
        
        if(covered.find(curr->left)==covered.end()||
          covered.find(curr->right)==covered.end()||
          (covered.find(curr)==covered.end()&&!parent)){
            ans++;
            covered.insert(curr);
            covered.insert(parent);
            covered.insert(curr->left);
            covered.insert(curr->right);
          }
    }
    int minCameraCover(TreeNode* root) {
        ans = 0;
        covered.insert(NULL);
        util(root, NULL);
        return ans;
    }
    
};