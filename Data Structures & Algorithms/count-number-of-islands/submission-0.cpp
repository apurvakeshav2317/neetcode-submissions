class Solution {
public:
    vector<int>dx={1,-1,0,0},dy={0,0,-1,1};
    void solve(vector<vector<char>>&grid,int x,int y,int n,int m){
        queue<pair<int,int>>q;
        q.push({x,y});
        grid[x][y]='0';
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int a=p.first+dx[i],b=p.second+dy[i];
                if(a<n && b<m && a>=0 && b>=0 && grid[a][b]=='1'){
                    q.push({a,b});
                    grid[a][b]='0';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1') {
                    solve(grid,i,j,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
