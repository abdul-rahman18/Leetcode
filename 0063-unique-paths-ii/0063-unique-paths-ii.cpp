class Solution {
public:
    //Recursion
    int path(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& dp)
    {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if(i>=n || j>=m) return 0;
        if(i==n-1 && j==m-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(obstacleGrid[i][j] == 1) return 0;

        return dp[i][j] = path(obstacleGrid,i+1,j,dp) + path(obstacleGrid,i,j+1,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if(obstacleGrid[n-1][m-1] == 1) return 0;

        vector<vector<int>>dp(n,vector<int>(m,-1));

        return path(obstacleGrid,0,0,dp);
    }
};