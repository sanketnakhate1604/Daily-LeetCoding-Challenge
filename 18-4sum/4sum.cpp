class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        if (n < 4) return ans;

        sort(nums.begin(), nums.end());

        for (int j = 0; j < n - 3; j++) {
            if (j > 0 && nums[j] == nums[j - 1]) continue; // skip duplicates

            for (int i = j + 1; i < n - 2; i++) {
                if (i > j + 1 && nums[i] == nums[i - 1]) continue; // skip duplicates

                int low = i + 1, high = n - 1;

                while (low < high) {
                    long long sum = (long long)nums[j] + nums[i] + nums[low] + nums[high];

                    if (sum == target) {
                        ans.push_back({nums[j], nums[i], nums[low], nums[high]});
                        low++;
                        high--;

                        while (low < high && nums[low] == nums[low - 1]) low++;
                        while (low < high && nums[high] == nums[high + 1]) high--;
                    }
                    else if (sum < target) {
                        low++;
                    }
                    else {
                        high--;
                    }
                }
            }
        }
        return ans;
    }
};
