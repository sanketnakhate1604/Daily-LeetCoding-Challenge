class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();

        unordered_map<int,int>mp;

        mp[0]=1;// intially zero size ka subaaraay present hai
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];

            if(mp.find(sum-k)!=mp.end()){
                // matlab aapne map mai aisa milga hai jisse aagar mai current vale dalu to k ke eqaul ho jaye
                count=count+mp[sum-k];

            }
            mp[sum]++;
        }

        return count;
    }
};