class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int,int>mp;

        for(int i = 0; i < n ; i++)
        {
            int remainingSum = target - nums[i];

            if(mp.find(remainingSum) != mp.end()) return { mp[remainingSum], i };

            mp[nums[i]] = i;
        }

        return {-1};
    }
};