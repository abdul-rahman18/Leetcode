class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        string ans = "";
        int oCnt = 0;

        int j = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1') oCnt++;

            while(j < i && oCnt > k)
            {
                if(s[j] == '1') oCnt--;

                j++;
            }

            while(j < i && s[j] == '0') j++;

            if(oCnt == k)
            {
                string temp = s.substr(j, i - j + 1);

                if(ans == "") ans = temp;
                else
                {
                    if(temp.size() > ans.size()) continue;

                    if(temp.size() < ans.size() || temp < ans) ans = temp;
                }
            }

        }

        return ans;
    }
};