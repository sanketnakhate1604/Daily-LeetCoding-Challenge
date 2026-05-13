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
    bool mirror(TreeNode *tree1 ,TreeNode* tree2){
         if(tree1==NULL && tree2==NULL){
            return true;
         }
         if(tree1==NULL || tree2==NULL){
            return false;
         }

         
         if(tree1->val != tree2->val){
            return false;
         }

         bool r1=mirror(tree1->left,tree2->right);
         bool r2=mirror(tree1->right,tree2->left);

         

         return r1 && r2;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }

        return  mirror(root->left,root->right);
    }
};