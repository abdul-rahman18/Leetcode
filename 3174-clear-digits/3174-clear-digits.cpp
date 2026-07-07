class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            if(s[i] >= '0' && s[i] <= '9')
            {
                st.insert(i);
                int j = i-1;
                while(j>=0 && s[j]>='0' && s[j]<='9') j--;
                if(j>=0)
                {
                    st.insert(j);
                    s[j] = '0';
                }
            }
        }

        string ans = "";
        for(int i=0;i<n;i++){
            if(st.find(i)==st.end()) ans += s[i];
        }
        return ans;
    }
};