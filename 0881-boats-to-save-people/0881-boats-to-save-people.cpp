class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l = 0;
        int cnt = 0;
        for(int i = n-1; i >= 0 && i >= l; i--)
        {
            if(nums[i] + nums[l] > limit) cnt++;
            else
            {
                l++;
                cnt++;
            }
        }

        return cnt;
    }
};