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
    int maxsum;

    int solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int l=solve(root->left);
        int r=solve(root->right);

        int es_se_accha_mil_hi_nahi_sakt=l+r+root->val;

        int dono_mai_se_kohi_ek_accha=max(l,r)+root->val;

        int root_hi_accha=root->val;

        maxsum=max(maxsum,max(es_se_accha_mil_hi_nahi_sakt,max(dono_mai_se_kohi_ek_accha,root_hi_accha)));

        return max(dono_mai_se_kohi_ek_accha,root_hi_accha);
    }
    int maxPathSum(TreeNode* root) {
        maxsum=INT_MIN;
        solve(root);
        return maxsum;
    }
};