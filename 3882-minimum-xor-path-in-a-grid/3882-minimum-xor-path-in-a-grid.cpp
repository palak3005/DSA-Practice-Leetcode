
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp;
        
        // dp[i][j] stores possible XOR values
        // for paths ending at cell (i, j)
        
        vector<vector<unordered_set<int>>> seen(
            m, vector<unordered_set<int>>(n)
        );

        seen[0][0].insert(grid[0][0]);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (i > 0) {
                    for (int x : seen[i - 1][j]) {
                        seen[i][j].insert(x ^ grid[i][j]);
                    }
                }

                if (j > 0) {
                    for (int x : seen[i][j - 1]) {
                        seen[i][j].insert(x ^ grid[i][j]);
                    }
                }
            }
        }

        return *min_element(
            seen[m - 1][n - 1].begin(),
            seen[m - 1][n - 1].end()
        );
    }
};
