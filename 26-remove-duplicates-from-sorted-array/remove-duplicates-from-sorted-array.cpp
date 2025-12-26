class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int n=nums.size();
       int low=0;
       int high=low+1;

       while(high<n){
        if(nums[low]==nums[high]){
            high++;
        }
        else{
            low=low+1;
            nums[low]=nums[high];
            
            high++;
        }
       } 
       return low+1;
    }
};