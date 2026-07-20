class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int num = (target[0] - start[0]) + (target[1] - start[1]);
        
        if(num%2==0) return true;
        
        return false;
    }
};