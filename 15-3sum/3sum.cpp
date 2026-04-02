class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;

        for(int i=0;i<=n-3;i++){
            int target=-nums[i];
            int low=i+1;
            int high=n-1;

            //to remove duplicate
            if(i!=0 && nums[i]==nums[i-1]){
                continue;
            }

            while(low<high){
                if(nums[low]+nums[high]==target){
                    ans.push_back({nums[i],nums[low],nums[high]});
                    low++;
                    high--;

                    // to remove low duplicate
                    while(low<high && nums[low]==nums[low-1]){
                         low++;
                    }
                    // to remove high duplicate

                    while(low<high && nums[high]==nums[high+1]){
                        high--;
                    }

                }
                

                else if(nums[low]+nums[high]<target){
                    low++;
                }
                else{
                    high--;
                }

            }
        }

    

        return ans;
    }
};