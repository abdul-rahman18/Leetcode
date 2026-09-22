class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();

        int freq[2001] = {0};
        for(int i = 0; i < n; i++) {
            freq[arr[i] + 1000]++;
        }

        sort(freq, freq + 2001);

        for(int i = 1; i < 2001; i++){
            if(freq[i] != 0 && freq[i] == freq[i-1]) return false;
        }

        return true;
    }
};