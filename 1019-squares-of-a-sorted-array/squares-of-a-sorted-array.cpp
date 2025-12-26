class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();

        vector<int>neg;
        vector<int>pos;

        for(int i=0;i<n;i++){
            if(nums[i]<0){
                neg.push_back(nums[i]*nums[i]);
            }
            else{
                pos.push_back(nums[i]*nums[i]);
            }
        }

        reverse(neg.begin(),neg.end());

        int low=0;
        int high=0;
        int i=0;

        while(low<neg.size() && high<pos.size()){
            if(neg[low]<pos[high]){
                nums[i]=neg[low];
                low++;
                i++;
            }
            else{
                nums[i]=pos[high];
                high++;
                i++;
            }
        }


        while(low<neg.size()){
            nums[i]=neg[low];
                low++;
                i++;
        }
        while(high<pos.size()){
            nums[i]=pos[high];
                high++;
                i++;
        }
        return nums;
    } 
};