class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token = "";
        
        string ans = "";

        while(ss >> token)
        {
            ans = token + " " + ans;
        }

        ans.pop_back();
        return ans;
    }
};