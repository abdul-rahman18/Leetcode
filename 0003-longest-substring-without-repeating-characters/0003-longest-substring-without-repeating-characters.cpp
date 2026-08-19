class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int l = 0;
        int mx = 0;
        unordered_map<char,int>mp;

        for(int r=0;r<n;r++){
            while(l<r && mp[s[r]]>=1)
            {
                mp[s[l]]--;
                l++;
            }

            mx = max(mx,r-l+1);
            mp[s[r]]++;
        }

        return mx;
    }
};