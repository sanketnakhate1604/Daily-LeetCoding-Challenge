class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int close_sum=nums[0]+nums[1]+nums[2];
        

        for(int i=0;i<n;i++){
            
            int low=i+1;
            int high=n-1;
            
            while(low<high){
                int sum=nums[i]+nums[low]+nums[high];
                if(abs(sum-target)<abs(close_sum-target)){
                    close_sum=sum;
                }

                if(sum==target){
                    return sum;
                }
                if(sum>target){
                    high--;
                }
                else{
                    low++;
                }
            }

        }
        return close_sum;
    }
    
};