class Solution {
public:
    int pathSum(vector<vector<int>>& grid, int I, int j1, int j2, vector<vector<vector<int>>>& dp)
    {
        int n = grid.size();
        int m = grid[0].size();

        if(I>=n || j1>=m || j2>=m || j1<0 || j2<0) return INT_MIN;

        if(I==n-1)
        {
            if(j1 == j2) return grid[I][j1];
            return grid[I][j1] + grid[I][j2];
        }

        if(dp[I][j1][j2]!=-1) return dp[I][j1][j2];

        int mx = INT_MIN;

        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                mx = max(mx,pathSum(grid,I+1,j1+i,j2+j,dp));
            }
        }

        if(j1 != j2) return dp[I][j1][j2] = grid[I][j1] + grid[I][j2] + mx;
        return dp[I][j1][j2] = grid[I][j1] + mx;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return pathSum(grid,0,0,grid[0].size()-1, dp);
    }
};