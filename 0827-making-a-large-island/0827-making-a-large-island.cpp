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
    vector<int>rows;
    vector<int>cols;
    Solution()
    {
        rows = {-1,0,1,0};
        cols = {0,1,0,-1};
    }
    bool valid(int i, int j, int n)
    {
        if(i>=0 && j>=0 && i<n && j<n) return true;
        return false;
    }

    int merge(vector<vector<int>>& grid, int i, int j, DisjointSet& d)
    {
        int n = grid.size();
        for(int k=0;k<4;k++)
        {
            int r = i + rows[k];
            int c = j + cols[k];

            if(valid(r,c,n) && grid[r][c]==1)
            {
                int u = r*n + c;
                int v = i*n + j;

                d.uni(u,v);
            }
        }
        int x = d.find(i*n + j);
        return -1*d.parent[x];
    }

    int getNodeCnt(vector<vector<int>>& grid, int i, int j, DisjointSet& d)
    {
        int n = grid.size();
        unordered_set<int>st;
        
        for(int k=0;k<4;k++)
        {
            int r = i + rows[k];
            int c = j + cols[k];

            if(valid(r,c,n) && grid[r][c]==1) 
                st.insert(d.find(r*n+c));
        }

        int sum = -1;
        for(auto x : st) sum += d.parent[x];
        return -1 * sum;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        DisjointSet d(n*n);

        int mx = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    mx = max(mx,merge(grid,i,j,d));
                }
            }
        }

        vector<vector<bool>>visited(n,vector<bool>(n,false));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0 && !visited[i][j])
                {
                    visited[i][j] = 1;
                    mx = max(mx,getNodeCnt(grid,i,j,d));
                }
            }
        }

        return mx;
    }
};