class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        // Step 1: Calculate total sum
        for(int i = 0; i < n; i++) {
            totalSum += nums[i];
        }

        int leftSum = 0;

        // Step 2: Traverse and check pivot
        for(int i = 0; i < n; i++) {
            int rightSum = totalSum - nums[i] - leftSum;

            if(leftSum == rightSum) {
                return i;
            }

            leftSum += nums[i];  // update after checking
        }

        return -1;
    }
};