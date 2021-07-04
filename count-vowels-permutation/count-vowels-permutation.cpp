class Solution {
public:
    int MOD = 1e9 + 7, LIM = 5;

    vector<vector<long long>> matrixMultiplication(vector<vector<long long>>& a, vector<vector<long long>>& b)
    {
        vector<vector<long long>> ret(LIM, vector<long long>(LIM, 0));

        for (int i = 0; i < LIM; i++)
            for (int j = 0; j < LIM; j++)
                for (int k = 0; k < LIM; k++)
                    ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % MOD;

        return ret;
    }

    int countVowelPermutation(int n)
    {
        vector<vector<long long>> dp(LIM, vector<long long>(LIM, 0));
        vector<vector<long long>> mat = {
            {0, 1, 0, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 1},
            {0, 0, 1, 0, 1},
            {1, 0, 0, 0, 0}
        };

        for (int i = 0; i < LIM; i++)
            dp[i][i] = 1;
        
        n--;

        while (n > 0)
        {
            if (n % 2 == 1)
                dp = matrixMultiplication(mat, dp);

            mat = matrixMultiplication(mat, mat);

            n /= 2;
        }

        int ans = 0;

        for (int i = 0; i < LIM; i++)
            for (int j = 0; j < LIM; j++)
                ans = (ans + dp[i][j]) % MOD;

        return ans;
    }
};