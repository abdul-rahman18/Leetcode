class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int n = s.size();
        string t = "";

        int xCnt = 0;
        int yCnt = 0;

        for(int i=0;i<n;i++){
            if(s[i]==x) xCnt++;
            else if(s[i]==y) yCnt++;
        }

        while(yCnt--) t+=y;
        while(xCnt--) t+=x;

        for(int i=0;i<n;i++){
            if(s[i]==x || s[i]==y) continue;
            else t += s[i];
        }
        
        return t;
    }
};