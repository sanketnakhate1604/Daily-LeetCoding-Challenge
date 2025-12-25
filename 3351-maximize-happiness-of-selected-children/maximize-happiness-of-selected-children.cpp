class Solution {
public:
    long long maximumHappinessSum(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        long long n=arr.size();
        long long ans=0;
        long long curr_min=0;
        for(int i=n-1;i>=0;i--){
             if(k==0){
                break;
             }

             if(arr[i]-curr_min<0){
                break;
             }
             ans=ans+(arr[i]-curr_min);
             curr_min++;
             k--;
        }

        return ans;
        
    }
};