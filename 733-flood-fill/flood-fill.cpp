class Solution {
public:
    int x[4]={-1,1,0,0};
    int y[4]={0,0,-1,1};

    bool valid(int i,int j,int n,int m){
        if(i<0||i>=n||j<0||j>=m){
            return  false;
        }

        return true;
    }
    void dfs(vector<vector<int>>& a,int i,int j,int n,int m,int color,int original,vector<vector<bool>>&vis, vector<vector<int>>&res){
        vis[i][j]=1;
        

        for(int k=0;k<4;k++){
            int row=i+x[k];
            int col=j+y[k];

            if(valid(row,col,n,m)&& a[row][col]==original && vis[row][col]==0){
                // ab colur kar or fhir se dfs call kar de
                res[row][col]=color;
                dfs(a,row,col,n,m,color,original,vis,res);

            }
        }

        return ;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& a, int i, int j, int color) {
        int n=a.size();
        int m=a[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));

        

        vector<vector<int>>res=a;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[i][j]=a[i][j];
            }
        }
         int original=a[i][j];
         res[i][j]=color;
         dfs(a,i,j,n,m,color,original,vis,res);

        return res;
    }
};