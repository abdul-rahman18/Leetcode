class DisjointSet {
   public:
    vector<int> parent;
    DisjointSet(int V) { parent.resize(V, -1); }
    int find(int node) {
        if (parent[node] < 0) return node;
        return parent[node] = find(parent[node]);
    }
    bool uni(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return true;
        if (parent[pu] <= parent[pv]) {
            parent[pu] += parent[pv];
            parent[pv] = pu;
        } else {
            parent[pv] += parent[pu];
            parent[pu] = pv;
        }
        return false;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int sz = stones.size();
        int n = 0, m = 0;
        for(auto& vec : stones)
        {
            n = max(n,vec[0]);
            m = max(m,vec[1]);
        }

        DisjointSet d(n+m+2);
        
        unordered_set<int>st;
        for(auto& vec : stones)
        {
            int u = vec[0];
            int v = n + vec[1] + 1;
            d.uni(u,v);
            st.insert(u);
            st.insert(v);
        }
        int cnt = 0;
        
        for(auto x : st)
        {
            if(d.find(x) == x) cnt++;
        }
        
        return sz - cnt;
    }
};