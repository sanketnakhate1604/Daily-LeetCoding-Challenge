class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums,vector<int>& val) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        

        int n=nums.size();
        if(n==0){
           ans.push_back(val);
           return ans;
        }
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
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& val) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        int valstart=val[0];
        int valend=val[1];

        
        bool insert=false;
        for(int i=0;i<n;i++){
            int start1=nums[i][0];
            int end1=nums[i][1];

            if(valstart<=end1 && valend>=start1 ){
                start1=min(start1,valstart);
                end1=max(end1,valend);
                nums[i][0]=start1;
                nums[i][1]=end1;
                insert=true;
                break;
            }


        }

        // ab merge interval wala code use kar na
        if(insert==false){
            nums.push_back(val);
            sort(nums.begin(),nums.end());
            return nums;
        }
        return  merge(nums,val);
    }
};