class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int colse_sum=nums[0]+nums[1]+nums[2];

        for(int i=0;i<=n-3;i++){
            int low=i+1;
            int high=n-1;

            while(low<high){
                int sum=nums[i]+nums[low]+nums[high];

                if(abs(colse_sum-target)>abs(sum-target)){
                    colse_sum=sum;
                }

                if(sum<target){
                    low++;
                }
                else{
                    high--;
                }
            }
        }

        return colse_sum;
    }
};