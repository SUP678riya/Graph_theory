class Solution {
public:

    bool dfs(int x,int y,int px,int py,vector<vector<char>>& grid,vector<vector<int>>&vis)
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>dx={1,-1,0,0};
        vector<int>dy={0,0,1,-1};
        vis[x][y]=1;
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(ny<0 || nx<0 || nx>=m || ny>=n) continue;
            if(grid[x][y]!=grid[nx][ny]) continue;
            if(!vis[nx][ny])
            {
                if(dfs(nx,ny,x,y,grid,vis))
                {
                    return true;
                }
            }
            else if(nx!=px || ny!=py)
            {
                return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j])
                {
                    if(dfs(i,j,-1,-1,grid,vis))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};