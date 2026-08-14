class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();

        int mx = 0;

        for(int i = 0 ; i < n ; i++){
            vector<int>alphabets(26,0);

            for(int j = i ; j < n; j++){
                alphabets[s[j] - 'a']++;

                if(alphabets[s[j] - 'a'] > 2) break;

                mx = max(mx, j-i+1);
            }
        }

        return mx;
    }
};