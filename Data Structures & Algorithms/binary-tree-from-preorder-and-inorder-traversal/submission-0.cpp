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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()||inorder.empty()){
            return nullptr;
        }
        TreeNode *root=new TreeNode(preorder[0]);
        int idx=0;
        for(int i=0;i<inorder.size();i++){
            if(root->val==inorder[i]){
                idx=i;
            }
        }
        vector<int> leftorder(preorder.begin()+1,preorder.begin()+1+idx);
        vector<int> leftinorder(inorder.begin(),inorder.begin()+idx);
        root->left=buildTree(leftorder,leftinorder);
        vector<int> rightorder(preorder.begin()+idx+1,preorder.end());
        vector<int> rightinorder(inorder.begin()+idx+1,inorder.end());
        root->right=buildTree(rightorder,rightinorder);
        return root;
    }
};
