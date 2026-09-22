class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        unordered_map<int,int>mp;
        
        for(int i = 0; i < n; i++) mp[matches[i][1]]++;

        vector<vector<int>>ans(2);
        for(auto x : matches)
        {
            int winner = x[0];
            int loser = x[1];

            if(mp.find(winner) == mp.end()) {
                ans[0].push_back(winner);
                mp[winner] = 2;
            }

            if(mp[loser] == 1) ans[1].push_back(loser);
        }

        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());

        return ans;
    }
};