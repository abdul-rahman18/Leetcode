class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long N = n*n;

        int sum = (N*(N+1)) / 2;
        long long sqSum = (N * (N+1) * (2*N + 1)) / 6;

        int gridSum = 0;
        long long gridSqSum = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                gridSum += grid[i][j];
                gridSqSum += (grid[i][j] * grid[i][j]);
            }
        }

        int sqDiff = gridSqSum - sqSum;
        int diff = gridSum - sum;

        int a = (sqDiff / diff + diff) / 2;
        int b = (sqDiff / diff - diff) / 2;

        return {a,b};
    }
};