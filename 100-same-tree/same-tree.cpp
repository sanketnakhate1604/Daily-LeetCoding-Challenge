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
    bool fun(TreeNode* tree1, TreeNode* tree2){
        if(tree1==NULL && tree2==NULL){
            return true;
        }

        if(tree1==NULL || tree2==NULL){
            return false;
        }

        if(tree1->val != tree2->val){
            return false;
        }

        bool r1=fun(tree1->left,tree2->left);

        bool r2=fun(tree1->right,tree2->right);

        if(r1==true && r2==true){
            return true;
        }

        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return fun(p,q);
    }
};