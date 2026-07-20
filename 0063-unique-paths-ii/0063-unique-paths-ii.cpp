class Solution {
public:
    //Tabulation
    int path(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<long long>>& dp)
    {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        dp[n-1][m-1] = 1;

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1) continue;

                if(i < n-1 && obstacleGrid[i][j]!=1) dp[i][j] += dp[i+1][j];
                if(j < m-1 && obstacleGrid[i][j]!=1) dp[i][j] += dp[i][j+1];
            }
        }

        return dp[0][0];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if(obstacleGrid[n-1][m-1] == 1) return 0;

        vector<vector<long long>>dp(n,vector<long long>(m,0));

        return path(obstacleGrid,0,0,dp);
    }
};