class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mp;

        int ans=-1;int prev=-1;
        int n=s.size();


         for(int i=0;i<n;i++){
            if(mp[s[i]]==0){
                mp[s[i]]++;
            }
            else{
                mp[s[i]]++;
            }
         }
        
        for(int i=0;i<n;i++){
            if(mp[s[i]]==1){
                return i;
            }
        }

        return -1;
    }
};