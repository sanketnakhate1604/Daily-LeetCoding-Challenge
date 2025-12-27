class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n=nums.size();
        int k=2;
        unordered_map<int,int>mp;
        int low=0;
        int high=0;
        int distinct=0;
        int len=0;

        while(high<n){
           if(mp[nums[high]]==0){
              
              distinct++;
           }
           mp[nums[high]]++;

           while(distinct>k){
             mp[nums[low]]--;
             if(mp[nums[low]]==0){
                distinct--;
                mp.erase(nums[low]);
             }
             low++;
           }
           len=max(len,high-low+1);
           high++;
        }

        return len;
    }
};