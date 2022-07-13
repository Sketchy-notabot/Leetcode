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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> temp;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(!curr){
                if(temp.size()==0)
                    break;
                ans.push_back(temp);
                temp.clear();
                q.push(NULL);
                continue;
            }
            temp.push_back(curr->val);
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        return ans;
    }
};