class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int>mp;

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += mp[nums[i]]++;
        }

        return cnt;
    }
};