class Solution {
public:
    int x[4]={-1,1,0,0};
    int y[4]={0,0,-1,1};

    bool vaild(int i,int j,int n,int m){
        if(i<0 || i>=n || j<0 ||j>=m){
            return false;
        }
        return true;
    }

    void dfs(vector<vector<char>>& a,int i,int j,int n,int m,vector<vector<bool>>&vis){
        vis[i][j]=1;

        for(int k=0;k<4;k++){
            int row=i+x[k];
            int col=j+y[k];

            // aab dekhege kya vaild bhi hai ya nahi

            if(vaild(row,col,n,m) && a[row][col]=='1' && vis[row][col]==0){
                // fhir se dfs call kar sakta nahi return ek iland mil gaya
                dfs(a,row,col,n,m,vis);
            }
        }

        return;
    }

    int numIslands(vector<vector<char>>& a) {
         int n=a.size();
         int m=a[0].size();
         int count=0;

         vector<vector<bool>>vis(n);

         for(int i=0;i<n;i++){
            vector<bool>t(m,0);
            vis[i]=t;
         }   

         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]=='1' && vis[i][j]==0){
                    dfs(a,i,j,n,m,vis);
                    count++;
                }
            }
         }

         return count;
    }
};