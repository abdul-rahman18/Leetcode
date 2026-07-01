class Solution {
public:
    int timer = 1;
    void dfs(int node, vector<int> adj[], vector<int>& tin, vector<int>& low, vector<bool>& visited, int parent, vector<vector<int>>& bridges)
    {
        visited[node] = 1;
        tin[node] = timer;
        low[node] = timer;

        timer++;
        
        for(auto v : adj[node])
        {
            if(v == parent) continue;

            if(!visited[v])
            {
                dfs(v,adj,tin,low,visited,node,bridges);
                low[node] = min(low[node],low[v]);

                if(low[v] > tin[node])
                {
                    bridges.push_back({v,node});
                }
            }
            else
            {
                low[node] = min(low[node],low[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        timer = 1;

        vector<int> adj[n];

        for(auto& vec : connections)
        {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>tin(n);
        vector<int>low(n);
        vector<bool>visited(n,false);

        vector<vector<int>>bridges;
        dfs(0,adj,tin,low,visited,-1,bridges);

        return bridges;
    }
};