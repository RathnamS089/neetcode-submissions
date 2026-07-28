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
    int dfs(TreeNode *root,int &res){
        if(root==nullptr){
            return 0;
        }
        int leftmax=dfs(root->left,res);
        int rightmax=dfs(root->right,res);
        leftmax=max(0,leftmax);
        rightmax=max(0,rightmax);
        res=max(res,root->val+leftmax+rightmax);
        return root->val+max(leftmax,rightmax);
    }
    int maxPathSum(TreeNode* root) {
       int res=root->val;
       dfs(root,res);
       return res;
    }
};
