class Solution {
public:
    vector<int>rows = {-1,0,1,0};
    vector<int>cols = {0,1,0,-1};

    bool valid(int i, int j, int n)
    {
        if(i>=0 && j>=0 && i<n && j<n) return true;
        return false;
    }
    bool isPossible(int mid, vector<vector<int>>& safeness, vector<vector<bool>>& visited, int i, int j)
    {
        int n = safeness.size();
        visited[i][j] = 1;

        if(safeness[i][j] < mid) return false;

        if(i==n-1 && j==n-1) return true;

        for(int k=0;k<4;k++)
        {
            int r = i + rows[k];
            int c = j + cols[k];
            if(valid(r,c,n) && !visited[r][c])
            {
                if(isPossible(mid, safeness, visited, r, c)) return true;
            }
        }

        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return 0;

        queue<pair<int,int>> q;
        vector<vector<int>> safeness(n, vector<int>(n, INT_MAX));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    safeness[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty())
        {
            auto [i,j]=q.front();
            q.pop();

            for(int k=0;k<4;k++)
            {
                int ni=i+rows[k];
                int nj=j+cols[k];

                if(valid(ni,nj,n) && safeness[ni][nj]==INT_MAX)
                {
                    safeness[ni][nj]=safeness[i][j]+1;
                    q.push({ni,nj});
                }
            }
        }

        int low = 0;
        int high = n;

        while(low<=high)
        {
            int mid = low + (high-low)/2;
            vector<vector<bool>>visited(n,vector<bool>(n,false));
            if(isPossible(mid, safeness, visited, 0, 0)) low = mid + 1;
            else high = mid - 1;
        }

        return high;
    }
};