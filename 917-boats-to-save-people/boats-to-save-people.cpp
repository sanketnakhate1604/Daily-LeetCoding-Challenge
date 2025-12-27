class Solution {
public:
    int numRescueBoats(vector<int>& arr, int target) {
        int n=arr.size();
        sort(arr.begin(),arr.end());

        int low=0;
        int high=n-1;
        int count =0;
        while(low<high){
            int sum=arr[low]+arr[high];
            if(sum<=target){
                count++;
                low++;
                high--;
            }
            else if(sum>target){
                if(arr[high]<=target){
                    count++;
                }
                high--;
            }
       
            
        }
        if(low==high){
            if(arr[low]<=target){
                count++;
            }
        }

        return count;
    }
};