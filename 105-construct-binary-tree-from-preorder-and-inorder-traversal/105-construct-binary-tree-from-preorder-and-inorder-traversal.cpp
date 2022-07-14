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
    int preIndex = 0;
    TreeNode* util(vector<int> preorder, vector<int> inorder, int inStart, int inEnd){
        if(inStart==inEnd){
            preIndex++;
            return new TreeNode(inorder[inEnd]);
        }
        if(inStart>inEnd)
            return NULL;
        int inCurr;
        for(int i=inStart;i<=inEnd;i++){
            if(inorder[i]==preorder[preIndex]){
                inCurr=i;
                break;
            }
        }
        TreeNode* curr = new TreeNode(inorder[inCurr]);
        preIndex++;
        curr->left = util(preorder, inorder, inStart, inCurr-1);
        curr->right = util(preorder, inorder, inCurr+1, inEnd);
        return curr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return util(preorder, inorder, 0, inorder.size()-1);
    }
};