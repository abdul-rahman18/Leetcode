class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        int i = 0;
        for(auto str : strs){
            sort(str.begin(),str.end());
            mp[str].push_back(strs[i++]);
        }

        vector<vector<string>>ans;
        for(auto& [k,v] : mp) ans.push_back(v);

        return ans;
    }
};