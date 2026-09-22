class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int,int>mp;
        for(auto x : arr) mp[x]++;

        unordered_set<int>st;
        for(auto& [k,v] : mp)
        {
            if(st.count(v)) return false;
            st.insert(v);
        }

        return true;
    }
};