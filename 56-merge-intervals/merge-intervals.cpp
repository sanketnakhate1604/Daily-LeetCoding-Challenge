class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        

        int n=nums.size();
        int start1=nums[0][0];
        int end1=nums[0][1];
        for(int i=1;i<n;i++){
           int start2=nums[i][0];
           int end2=nums[i][1];

           if(start2<=end1){
             start1=start1;
             end1=max(end1,end2);
             continue;
           }

           // aagar nahi hai toh simple push kar de

           ans.push_back({start1,end1});

           start1=start2;
           end1=end2;
        }
        // ye last wale ke liye hai
        ans.push_back({start1,end1});

        return ans;
    }
};