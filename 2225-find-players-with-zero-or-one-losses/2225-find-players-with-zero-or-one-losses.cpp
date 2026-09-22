class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        unordered_map<int,int>mp;
        sort(matches.begin(), matches.end());
        
        for(int i = 0; i < n; i++) mp[matches[i][1]]++;

        vector<vector<int>>ans(2);
        for(auto [k,v] : mp){
            if(v == 1) ans[1].push_back(k);
        }

        for(auto x : matches)
        {
            if(mp.find(x[0]) == mp.end() && (ans[0].size() == 0 || x[0] != ans[0].back())) ans[0].push_back(x[0]);
        }

        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());

        return ans;
    }
};