class Solution {
public:
    int n;
    bool generate(int idx, string& s, int val, vector<vector<int>>& dp) {
        if(idx == n) return val == 0;

        if(dp[idx][val] != -1) return dp[idx][val];

        bool ans = false;
        if(s[idx] == '*') {
            ans = ans | generate(idx+1, s, val + 1, dp);

            ans = ans | generate(idx+1, s, val, dp);

            if(val > 0) ans = ans | generate(idx+1, s, val - 1, dp);
        }
        else if(s[idx] == '(') ans = ans | generate(idx+1, s, val + 1, dp);
        else if(val > 0) ans = ans | generate(idx+1, s, val - 1, dp);

        return dp[idx][val] = ans;
    }
    bool checkValidString(string s) {
        n = s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return generate(0, s, 0, dp);
    }
};