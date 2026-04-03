class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=0;
        long long sum=0;
        int maxlen=INT_MAX;

        while(high<n){
            sum=sum+nums[high];

            while(sum>=target){
                maxlen=min(maxlen,high-low+1);
                sum=sum-nums[low];
                low++;                                                               
            }
            high++;
            
        }
        if(maxlen==INT_MAX){
            return 0;
        }

        return maxlen;
    }
};