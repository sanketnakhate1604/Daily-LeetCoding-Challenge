class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n=nums.size();
        int  len=0;

        int distinct=0;
        int low=0;
        int high=0;
        int k=2;
        unordered_map<int,int>ans;

        while(high<n){
           if(ans[nums[high]]==0){
              distinct++;
           }
           ans[nums[high]]++;

           while(distinct>k){
              ans[nums[low]]--;
              if(ans[nums[low]]==0){
                distinct--;
              }
              low++;
           }

           len=max(len,high-low+1);
           high++;
        }

        return len;
    }
};