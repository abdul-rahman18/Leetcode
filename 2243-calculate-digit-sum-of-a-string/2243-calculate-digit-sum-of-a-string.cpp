class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k){
            string str = "";

            int i = 0;
            int j = 0;
            int sum = 0;
            while(i < s.size()) {
                j++;
                if(j > k){
                    str += to_string(sum);
                    sum = 0;
                    j = 1;
                }

                sum += (s[i] - '0');
                i++;
            }
            if(j <= k) str += to_string(sum);
            s = str;
        }

        return s;
    }
};