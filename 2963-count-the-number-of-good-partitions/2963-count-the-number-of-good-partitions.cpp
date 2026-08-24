class Solution {
public:
    int m = 1e9+7;
    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++) mp[nums[i]] = i; //last idx

        int i = 0;
        int j = 0; j = max(j, mp[nums[0]]);
        
        int cnt = 1;
        while(i < n)
        {
            if(i > j) cnt = (cnt%m * 2%m)%m;

            j = max(j, mp[nums[i]]);

            i++;
        }

        return cnt;
    }
};