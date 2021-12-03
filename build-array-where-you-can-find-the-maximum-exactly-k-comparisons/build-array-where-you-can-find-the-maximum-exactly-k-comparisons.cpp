const int MOD = 1e9 + 7;

class Solution {
public:
    int numOfArrays(int n, int m, int cost) 
    {
        long long int dp[n][m+1][cost+1];
        
        memset(dp, 0, sizeof(dp));
        
        for(int j=1; j<=m; ++j)
            dp[0][j][1] = 1;
        
        for(int i=1; i<n; ++i)
        {
            for(int j=1; j<=m; ++j)
            {
                for(int k=1; k<=min(j, cost); ++k)
                {
                    dp[i][j][k] = (dp[i-1][j][k] * j) % MOD;
                    
                    for(int l=1; l<j; ++l)
                        dp[i][j][k] = (dp[i][j][k] + dp[i-1][l][k-1]) % MOD;
                }
            }
        }
        
        int ans = 0;
        
        for(int j=1; j<=m; ++j)
            ans = (ans + dp[n-1][j][cost]) % MOD;
        
        return ans;
    }
};

/*
DP State
dp[i][j][k] -> num of arrays when i elements, j largest element and k cost

Transition
dp[i-1][j][k] * j
dp[i-1][1][k-1]
dp[i-1][2][k-1]
...
dp[i-1][j-1][k-1]
*/