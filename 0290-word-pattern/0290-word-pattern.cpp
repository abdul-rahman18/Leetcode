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

        unordered_map<string,char>mp;
        bool used[27] = {false};
        for(int i = 0; i < n; i++){
            if(mp.find(x[i]) != mp.end()){
                if(mp[x[i]] != pattern[i]) return false;
            }
            else{
                if(used[pattern[i] - 'a']) return false;

                mp[x[i]] = pattern[i];
                used[pattern[i] - 'a'] = 1;
            }
        }

        return true;
    }
};