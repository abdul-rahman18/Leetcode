class Solution {
public:
    int pathSum(vector<int>& nums, int start, int end)
    {
        int prev0 = nums[start];
        int prev1 = max(nums[start],nums[start+1]);
        int curr;

        for(int i=start+2;i<=end;i++)
        {
            int pick = prev0 + nums[i];
            int notPick = prev1;

            curr = max(pick,notPick);

            prev0 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);

        return max(pathSum(nums,0,n-2), pathSum(nums,1,n-1));
    }
};