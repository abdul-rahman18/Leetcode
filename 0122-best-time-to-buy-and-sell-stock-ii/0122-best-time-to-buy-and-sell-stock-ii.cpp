class Solution {
public:
    int buyStock(vector<int>& prices, int idx, bool bought, vector<vector<int>>& dp){
        int n = prices.size();
        if(idx == n) return 0;

        if(dp[idx][bought]!=-1) return dp[idx][bought];

        int p1,p2;
        if(!bought){
            p1 = -prices[idx] + buyStock(prices,idx+1,true,dp);
            p2 = 0 + buyStock(prices,idx+1,false,dp);
        }else{
            p1 = prices[idx] + buyStock(prices,idx+1,false,dp);
            p2 = 0 + buyStock(prices,idx+1,true,dp);
        }

        return dp[idx][bought] = max(p1,p2);
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return buyStock(prices,0,false,dp);
    }
};