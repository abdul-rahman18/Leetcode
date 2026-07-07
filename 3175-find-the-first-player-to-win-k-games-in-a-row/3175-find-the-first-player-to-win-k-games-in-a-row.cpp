class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int K) {
        int n = skills.size();

        if(K >= n) return max_element(skills.begin(),skills.end()) - skills.begin();
        
        deque<int>q;
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++) q.push_back(i);

        while(true){
            int i = q.front();
            q.pop_front();

            int j = q.front();
            q.pop_front();

            if(skills[i] > skills[j])
            {
                mp[i]++;
                mp[j] = 0;

                if(mp[i] == K) return i;
                q.push_back(j);
                q.push_front(i);
            }
            else
            {
                mp[j]++;
                mp[i] = 0;

                if(mp[j] == K) return j;
                q.push_back(i);
                q.push_front(j);
            }
        }
        return -1;
    }
};