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
    void dfs(TreeNode *node,int targetSum,bool &b){
        if(node==nullptr){
            return;
        }
        if(node->left==nullptr&&node->right==nullptr){
            if(node->val==targetSum){
                b=true;
            }
            return;
        }
        dfs(node->left,targetSum-node->val,b);
        dfs(node->right,targetSum-node->val,b);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool found=false;
        dfs(root,targetSum,found);
        return found;
    }
};