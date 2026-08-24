class Solution {
public:
    int m = 1e9 + 7;

    vector<int>power;

    Solution()
    {
        power.resize(1e5+1);
        power[0] = 1;
        for(int i=1;i<=1e5;i++)
        {
            power[i] = (power[i-1]%m * 2)%m;
        }
    }
    
    int numSubseq(vector<int>& nums, int target) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int l = 0;
        int r = n-1;
        
        int cnt = 0;

        while(l <= r)
        {
            int sum = nums[l] + nums[r];

            if(sum <= target)
            {
                cnt = ((int)cnt%m + (int)(power[r - l])%m)%m; 

                l++;
            }
            else r--;
        }

        return cnt;
    }
};