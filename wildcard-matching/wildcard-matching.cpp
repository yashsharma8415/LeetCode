class Solution {
public:
    bool isMatch(string s, string p) 
    {
        string x = "";
        int i = 0;

        while (i < p.length())
        {
            if (p[i] != '*')
                x += p[i++];
            else if (p[i] == '*')
            {
                x += p[i++];
                while (p[i] == '*') i++;
            }
        }

        int a = s.length();
        int b = x.length();

        vector<vector<int>> dp(a + 1, vector<int> (b + 1, -1));
        dp[0][0] = 1;

        for (int i = 1; i <= a; i++)
            dp[i][0] = 0;
        
        for (int i = 1; i <= b; i++)
        {
            if (x[i - 1] == '*')
                dp[0][i] = dp[0][i - 1];
            else
                dp[0][i] = 0;
        }

        for (int i = 1; i <= a; i++)
        {
            for (int j = 1; j <= b; j++)
            {
                if (s[i - 1] == x[j - 1] || x[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (x[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                else
                    dp[i][j] = 0;
            }
        }

        return dp[a][b];
    }
};