class Solution {
public:
    int MOD = 1e9 + 7;

    int countVowelPermutation(int n)
    {
        long long dp[2][5];

        dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = dp[0][4] = 1;

        for (int i = 1; i < n; ++i)
        {
            dp[i % 2][0] = (dp[(i + 1) % 2][1]) % MOD;
            dp[i % 2][1] = (dp[(i + 1) % 2][0] + dp[(i + 1) % 2][2]) % MOD;
            dp[i % 2][2] = (dp[(i + 1) % 2][0] + dp[(i + 1) % 2][1] + dp[(i + 1) % 2][3] + dp[(i + 1) % 2][4]) % MOD;
            dp[i % 2][3] = (dp[(i + 1) % 2][2] + dp[(i + 1) % 2][4]) % MOD;
            dp[i % 2][4] = (dp[(i + 1) % 2][0]) % MOD;
        }

        int ans = (dp[(n + 1) % 2][0] + dp[(n + 1) % 2][1] + dp[(n + 1) % 2][2] + dp[(n + 1) % 2][3] + dp[(n + 1) % 2][4]) % MOD;

        return ans;
    }
};