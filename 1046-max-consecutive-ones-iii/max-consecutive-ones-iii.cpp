class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int low=0;
        int high=0;
        int len=0;
        int count_of_zeros=0;

        while(high<n){
            if(nums[high]==0){
                count_of_zeros++;
            }

            while(count_of_zeros>k){
                if(nums[low]==0){
                    count_of_zeros--;
                }
                low++;
            }

            len=max(len,high-low+1);
            high++;
        }

        return len;
    }
};