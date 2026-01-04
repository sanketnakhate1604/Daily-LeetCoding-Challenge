class Solution {
public:
    int t[101];
    int f(int i,int n,vector<int>& nums){
        if(i>=n){
            return 0;
        }
        if(t[i]!=-1){
            return t[i];
        }
        int  steal=nums[i]+f(i+2,n,nums);
        int skip=f(i+1,n,nums);

        return t[i]=max(steal,skip);
    }

    int rob(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        int n=nums.size();
    

        int i=0;
        return f(i,n,nums);
    }
};