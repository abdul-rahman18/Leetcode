class Solution {
public:
    int k;
    int buyAndSellStocks(vector<int>& prices, int idx, bool bought, int transaction,  vector<vector<vector<int>>>& dp)
    {
        int n = prices.size();

        if(idx == n) return 0;

        if(transaction == k) return 0;
        
        if(dp[idx][bought][transaction] != -1) return dp[idx][bought][transaction];

        int p1,p2;
        if(bought)
        {
            p1 = prices[idx] + buyAndSellStocks(prices,idx+1,false,transaction+1,dp);
            p2 = 0 + buyAndSellStocks(prices,idx+1,true,transaction,dp);
        }
        else
        {
            p1 = -prices[idx] + buyAndSellStocks(prices,idx+1,true,transaction,dp);
            p2 = 0 + buyAndSellStocks(prices,idx+1,false,transaction,dp);
        }

        return dp[idx][bought][transaction] = max(p1,p2);
    }
    int maxProfit(int K, vector<int>& prices) {
        k = K;
        int n = prices.size();
        vector<vector<vector<int>>>dp (n, vector<vector<int>>(2, vector<int>(k,-1)));
        return buyAndSellStocks(prices,0,false,0,dp);
    }
};