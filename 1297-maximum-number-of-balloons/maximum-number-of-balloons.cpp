class Solution {
public:
    int maxNumberOfBalloons(string s) {
        int n=s.size();

        unordered_map<char,int>mp;

        for(int i=0;i<n;i++){
            if(mp[s[i]]==0){
                mp[s[i]]++;
            }
            
            else{
                mp[s[i]]++;
            }
        }

        string res="balon";

        int m=res.size();
     

        vector<int>ans(5,0);
        for(int i=0;i<5;i++){
            ans[i]=mp[res[i]];
        }

        for(int i=0;i<m;i++){
            if(ans[i]==0){
                return 0;
            }

            
        }
        ans[2]=ans[2]/2;
        ans[3]=ans[3]/2;
        

        int mini=INT_MAX;

        for(int i=0;i<5;i++){
            mini=min(ans[i],mini);
        }


        if(mini==INT_MAX){
            return 0;
        }
        return mini;
    }
};