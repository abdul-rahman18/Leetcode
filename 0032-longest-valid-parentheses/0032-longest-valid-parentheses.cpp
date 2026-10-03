class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();

        int mx = 0;

        int oc = 0;
        int cc = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') oc++;
            else cc++;

            if(oc == cc) mx = max(mx, oc + cc);
            else if(cc > oc) oc = cc = 0;
        }

        oc = 0;
        cc = 0;
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == '(') oc++;
            else cc++;

            if(oc == cc) mx = max(mx, oc + cc);
            else if(oc > cc) oc = cc = 0;
        }

        return mx;
    }
};