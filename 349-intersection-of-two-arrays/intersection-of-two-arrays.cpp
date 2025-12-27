class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
          int n=nums1.size();
          int m=nums2.size();

          sort(nums1.begin(),nums1.end());
          sort(nums2.begin(),nums2.end());

          vector<int>ans;

          int low=0;
          int high=0;

          while(low<n && high<m){
                if(nums1[low]==nums2[high]){
                    ans.push_back(nums1[low]);
                    
                     int val = nums1[low];
                     while (low < n && nums1[low] == val) low++;
                    while (high < m && nums2[high] == val) high++;
                }

                 else if(nums1[low]>nums2[high]){
                    high++;
                 }
                 else{
                    low++;
                 }

            }
          

         return ans;
    }
};