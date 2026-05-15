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
    unordered_map<int,int>in;
    int index=0;

    TreeNode* fun(vector<int>& preorder,int low ,int high){
        if(low>high){
            return NULL;
        }

        TreeNode* node=new TreeNode(preorder[index]);
        index++;
        
        // left mai daal
        int id=in[node->val];
        node->left=fun(preorder,low,id-1);

        // right mai daal
        node->right=fun(preorder,id+1,high);

        return node;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();

        for(int i=0;i<n;i++){
            in[inorder[i]]=i;
        }


        return fun(preorder,0,n-1);


    }
};