class Solution {
public:
    void dfs(vector<vector<int>>&adj,int node,vector<bool>&vis){
        vis[node]=1;

        for(int i=0;i<adj[node].size();i++){
            int padhosi=adj[node][i];

            if(vis[padhosi]==0){
                dfs(adj,padhosi,vis);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();

        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool>vis(n,0);
        int count=0;

        for(int i=0;i<n;i++){
            if(vis[i]==0){
                count++;
                dfs(adj,i,vis);
            }
        }

        return count;

        
    }
};