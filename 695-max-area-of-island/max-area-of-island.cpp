class Solution {
public:
    int x[4]={-1,1,0,0};
    int y[4]={0,0,-1,1};


    bool valid(int i,int j,int n,int m){
        if(i<0||i>=n || j<0||j>=m){
            return false;
        }
        return true;
    }

    int dfs(vector<vector<int>>& grid,int i,int j,int n,int m,vector<vector<bool>>&vis,int len){
        len=1;
        vis[i][j]=1;

        for(int k=0;k<4;k++){
            int row=i+x[k];
            int col=j+y[k];

            if(valid(row,col,n,m) && grid[row][col]==1 && vis[row][col]==0){
                len=len+dfs(grid,row,col,n,m,vis,len);
            }
        }

        return len;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<bool>>vis(n);

        for(int i=0;i<n;i++){
            vector<bool>t(m,0);
            vis[i]=t;
        } 

        int len=0;
        int maxlen=INT_MIN;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    
                    maxlen=max(maxlen,dfs(grid,i,j,n,m,vis,0));
                }
            }
        }

       if(maxlen==INT_MIN){
        return 0;
       } 

        return maxlen;


    }
};