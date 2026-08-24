class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int mx = INT_MIN;
        for(int i = 0; i <= n/2; i++){
            mx = max(mx, nums[i] + nums[n - i - 1]);
        }

        return mx;
    }
};