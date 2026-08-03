class Solution {
public:
    int game(vector<int>& stoneValue, int i, vector<int>& dp)
    {
        int n = stoneValue.size();
        if(i >= n) return 0;

        if(dp[i]!=-1) return dp[i];

        int ans = INT_MIN;

        ans = max(ans,stoneValue[i] - game(stoneValue,i+1,dp));
        if(i+1 < n) ans = max(ans,stoneValue[i] + stoneValue[i+1] - game(stoneValue,i+2,dp));
        if(i+2 < n) ans = max(ans,stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - game(stoneValue,i+3,dp));

        return dp[i] = ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int>dp(n,-1);

        int x = game(stoneValue,0,dp);

        if(x > 0) return "Alice";
        if(x < 0) return "Bob";
        return "Tie";
    }
};