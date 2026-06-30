class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        unordered_map<string,int>mp;
        vector<int>vowels(5,0);
        string curr = "00000";
        mp[curr] = -1;
        int mx = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a') vowels[0] = (vowels[0] + 1)%2;
            else if(s[i]=='e') vowels[1] = (vowels[1] + 1)%2;
            else if(s[i]=='i') vowels[2] = (vowels[2] + 1)%2;
            else if(s[i]=='o') vowels[3] = (vowels[3] + 1)%2;
            else if(s[i]=='u') vowels[4] = (vowels[4] + 1)%2;

            curr = "";
            for(int j=0;j<5;j++)
            {
                curr += to_string(vowels[j]);
            }

            if(mp.find(curr)!=mp.end()) mx = max(mx,i-mp[curr]);
            else mp[curr] = i;
        }

        return mx;
    }
};