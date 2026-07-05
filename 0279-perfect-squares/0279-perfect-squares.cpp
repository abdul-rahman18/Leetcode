class Solution {
public:
    vector<int>dp;

    Solution() { dp.resize(10001,-1); }

    int func(int n)
    {
        if(n == 0) return 0;

        if(dp[n]!=-1) return dp[n];

        int mn = INT_MAX;

        for(int i=1;i*i<=n;i++) mn = min( mn, 1+func(n-i*i));

        return dp[n] = mn;
    }
    int numSquares(int n) {
        return func(n);
    }
};