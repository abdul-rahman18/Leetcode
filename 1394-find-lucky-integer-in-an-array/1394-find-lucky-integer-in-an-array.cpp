class Solution {
public:
    int findLucky(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++) mp[nums[i]]++;

        int mx = -1;
        for(auto [num, freq] : mp){
            if(num == freq) mx = max(mx, num);
        }

        return mx;
    }
};