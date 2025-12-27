class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        int ans=INT_MIN;

        while(low<high){
            int res=min(arr[low],arr[high])*(high-low);
            ans=max(ans,res);
            
            if(arr[low]>arr[high]){
                high--;
            }
            else{
                low++;
            }
        }

        return ans;
    }
};