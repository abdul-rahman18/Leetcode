class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int breakPoint = -1;

        for(int i=n-1;i>0;i--){
            if(nums[i-1] < nums[i]){
                breakPoint = i-1;
                break;
            }
        }

        if(breakPoint == -1)
        {
            sort(nums.begin(),nums.end());
            return;
        }

        int idx = -1;
        for(int i=breakPoint+1;i<n;i++){
            if(idx == -1 && nums[i] > nums[breakPoint]) idx = i;
            else if(idx!=-1 && nums[i]>nums[breakPoint] && nums[i]<nums[idx]) idx = i;
        }

        swap(nums[breakPoint],nums[idx]);
        sort(nums.begin()+breakPoint+1,nums.end());
    }
};