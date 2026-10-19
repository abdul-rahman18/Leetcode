class Solution {
public:
    int mod = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();

        sort(arr.begin(), arr.end());

        unordered_map<int, long long>mp;
        mp[arr[0]] = 1;

        for(int i = 1; i < n; i++) {
            mp[arr[i]] = 1;

            for(int j = 0; j < i; j++) {
                
                int lc = arr[j];
                int rc = arr[i] / lc;

                if((arr[i]%lc == 0) && (mp[rc] != 0)){
                    mp[arr[i]] += mp[lc] * mp[rc];
                }
            }
        }

        long long cnt = 0;
        for(auto& [k, v] : mp) {
            cnt = (cnt%mod + v%mod) % mod;
        }

        return cnt;
    }
};