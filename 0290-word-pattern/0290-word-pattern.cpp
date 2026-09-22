class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size();

        stringstream ss(s);
        vector<string>x;
        string token;
        while(getline(ss,token,' '))
        {
            if((token[0]>='a' && token[0]<='z') || (token[0]>='A' && token[0]<='Z')) x.push_back(token);
        }

        if(n != x.size()) return false;

        unordered_map<char,string>mp;
        unordered_set<string>st;
        for(int i = 0; i < n; i++){
            if(mp.find(pattern[i]) != mp.end()){
                if(mp[pattern[i]] != x[i]) return false;
            }
            else
            {
                if(st.count(x[i])) return false;
                mp[pattern[i]] = x[i];
                st.insert(x[i]);
            }
        }

        return true;
    }
};