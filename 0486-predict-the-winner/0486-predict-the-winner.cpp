class Solution {
public:
    bool game(vector<int>& nums, int score1, int score2, int l, int h, bool take)
    {
        if(l>h) return score1 >= score2;

        bool s,e;
        if(take)
        {
            s = game(nums,score1+nums[l],score2,l+1,h,false);
            e = game(nums,score1+nums[h],score2,l,h-1,false);

            return s || e;
        }
        else
        {
            s = game(nums,score1,score2+nums[l],l+1,h,true);
            e = game(nums,score1,score2+nums[h],l,h-1,true);

            return s && e;
        }

        return false;
    }
    bool predictTheWinner(vector<int>& nums) {
        return game(nums,0,0,0,nums.size()-1,true);
    }
};