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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        queue<TreeNode*>q;
        q.push(root);
        int res=INT_MIN;
        int level=0;
        int ans=-1;

        while(q.empty()==0){
            int size=q.size();
            int sum=0;

            for(int i=0;i<size;i++){
                TreeNode*temp=q.front();
                sum=sum+temp->val;
                q.pop();

                if(temp->left){
                    q.push(temp->left);
                }

                if(temp->right){
                    q.push(temp->right);
                }

            }
            level++;
            if(sum>res){
                res=sum;
                ans=level;

            }

        }

        return ans;
    }
};