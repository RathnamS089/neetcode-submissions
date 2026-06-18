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
    int dfs(TreeNode* node,int maxvalue){
        if(node==nullptr){
            return 0;
        }
        int res;
        if(node->val>=maxvalue){
            res=1;
        }
        else{
            res=0;
        }
        maxvalue=max(maxvalue,node->val);
        res+=dfs(node->left,maxvalue);
        res+=dfs(node->right,maxvalue);
        return res;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
};
