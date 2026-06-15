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
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
          int qlen=q.size();
          vector<int> level;
          for(int i=0;i<qlen;i++){
            TreeNode *n=q.front();
            q.pop();
            if(n!=nullptr){
              level.push_back(n->val);
              q.push(n->left);
              q.push(n->right);
            }
          }
          if(!level.empty()){
            res.push_back(level);
          }
        }
        return res;
    }
};
