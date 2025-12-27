class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        vector<int>ans(256,0);

        int low=0;
        int high=0;
        int len=0;

        for(int high=0;high<n;high++){
            ans[s[high]]++;
            while(ans[s[high]]>1){
                ans[s[low]]--;
                low++;
            }
            len=max(len,high-low+1);

        }
        return len;
    }
};