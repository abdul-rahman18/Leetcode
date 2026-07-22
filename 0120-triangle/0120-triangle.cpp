class Solution {
public:
    int minimum(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp,int n){
        //int n = triangle.size();

        if(i == n-1) return triangle[i][j];
        if(dp[i][j] != 1e9) return dp[i][j];

        return dp[i][j] = triangle[i][j] + min(minimum(triangle,i+1,j,dp,n), minimum(triangle,i+1,j+1,dp,n));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        if(triangle.size()==1) return triangle[0][0];

        vector<vector<int>>dp(n,vector<int>(n,1e9));
        return minimum(triangle,0,0,dp,n);
    }
};