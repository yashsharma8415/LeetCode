class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid)
    {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        dp[0][0] = grid[0][0];

        for (int t = 1; t <= 2 * n - 2; ++t)
        {
            vector<vector<int>> tdp(n, vector<int>(n, INT_MIN));
            int r1 = max(0, t - (n - 1)), r2 = min(n - 1, t);

            for (int i = r1; i <= r2; ++i)
            {
                for (int j = r1; j <= r2; ++j)
                {
                    if (grid[i][t - i] == -1 || grid[j][t - j] == -1)
                        continue;

                    int val = grid[i][t - i];

                    if (i != j)
                        val += grid[j][t - j];

                    tdp[i][j] = max(tdp[i][j], dp[i][j] + val);

                    if (i - 1 >= 0)
                        tdp[i][j] = max(tdp[i][j], dp[i - 1][j] + val);

                    if (j - 1 >= 0)
                        tdp[i][j] = max(tdp[i][j], dp[i][j - 1] + val);

                    if (i - 1 >= 0 && j - 1 >= 0)
                        tdp[i][j] = max(tdp[i][j], dp[i - 1][j - 1] + val);
                }
            }

            dp = tdp;
        }

        int ans = max(0, dp[n - 1][n - 1]);

        return ans;
    }
};