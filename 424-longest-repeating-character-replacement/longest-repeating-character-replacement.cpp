class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        vector<int>ans(26,0);
        int low=0;
        int high=0;
        int maxfreq=0;
        int answer=0;

        while(high<n){

            ans[s[high]-'A']++;

            maxfreq=max(maxfreq,ans[s[high]-'A']);
            // ye mujhe check kar ke de ra ha ki maine kitne chacter replace kiye hai
            while((high-low+1)-maxfreq>k){
              ans[s[low]-'A']--;
              low++;

            }

            answer=max(answer,high-low+1);
            high++;
        }

        return answer; 
    }
};