class Solution {
public: 
    bool ok = true;
    void dfs(vector<vector<int>>& a,int node,int c,vector<int>&colors){
         colors[node]=c;

         // es ke padhosi discover maro

         for(int i=0;i<a[node].size();i++){
            int padhosi=a[node][i];

            if(colors[padhosi]!=-1 && colors[padhosi]==c){
                ok=false;
                return ;
            }

            if(colors[padhosi]==-1){
                dfs(a,padhosi,1-c,colors);
            }
         }
         return ;
    }
    bool isBipartite(vector<vector<int>>& a) {
        int n=a.size();

        vector<int>colors(n,-1);

        int c;

        for(int i=0;i<n;i++){
            if(colors[i]==-1){
                dfs(a,i,0,colors);
            }
        }

        return ok;
    }
};