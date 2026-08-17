class Solution {
public:
    bool validate(vector<int>& time, long long mid, int totalTrips)
    {
        int n = time.size();
        long long cnt = 0;

        for(int i=0;i<n;i++) cnt += mid / time[i];

        return cnt >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {

        int n = time.size();

        if(n == 1) return 1LL * time[0] * totalTrips;

        sort(time.begin(),time.end());

        long long l = 0;
        long long h = 1LL * (*min_element(time.begin(),time.end())) * totalTrips;

        while(l <= h)
        {
            long long mid = l + (h - l) / 2;
            if(validate(time, mid, totalTrips)) h = mid - 1;
            else l = mid + 1;
        }

        return l;
    }
};