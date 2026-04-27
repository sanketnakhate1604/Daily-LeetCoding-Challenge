class Solution {
public:
    int x[4]={-1,1,0,0};
    int y[4]={0,0,-1,1};

    bool valid(int i,int j,int n,int m){
        if(i<0||i>=n||j<0||j>=m){
            return false;
        }
        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& a, int src, int dest, int color) {
        int n=a.size();
        int m=a[0].size();
        int element=a[src][dest];
        queue<pair<int,int>>q;

        q.push({src,dest});
        a[src][dest]=color;
        vector<vector<bool>>vis(n);
        for(int i=0;i<n;i++){
            vector<bool>t(m,0);
            vis[i]=t;
        }
        vis[src][dest]=1;

        while(q.empty()==0){
           pair<int,int>p=q.front();
           q.pop();

           int r=p.first;
           int c=p.second;

           for(int k=0;k<4;k++){
            int row=r+x[k];
            int col=c+y[k];
             if(valid(row,col,n,m)&&a[row][col]==element&&vis[row][col]==0){
                q.push({row,col});
                vis[row][col]=1;
                a[row][col]=color;
             }
           }
        }

        return a;
    }
};