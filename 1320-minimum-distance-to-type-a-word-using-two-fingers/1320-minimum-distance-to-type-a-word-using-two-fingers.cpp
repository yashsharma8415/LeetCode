class Solution {
public:
    int getDistance(int x1, int x2)
    {        
        if(x1 == 26 || x2 == 26)
            return 0;
        
        int r1 = x1 / 6, c1 = x1 % 6;
        int r2 = x2 / 6, c2 = x2 % 6;
        
        return abs(r2 - r1) + abs(c2 - c1);
    }
    
    int minimumDistance(string word) 
    {
        int n = word.size();
        int dp[n][27][27];
        
        for(int i=0; i<n; ++i)
            for(int j=0; j<=26; ++j)
                for(int k=0; k<=26; ++k)
                    dp[i][j][k] = 1e6;
        
        int x = word[0] - 'A';
        
        dp[0][x][26] = 0;
        dp[0][26][x] = 0;
        
        for(int i=1; i<n; ++i)
        {
            for(int j=0; j<=26; ++j)
            {
                for(int k=0; k<=26; ++k)
                {
                    x = word[i] - 'A';
                    
                    dp[i][x][k] = min(dp[i][x][k], dp[i-1][j][k] + getDistance(x, j));
                    dp[i][j][x] = min(dp[i][j][x], dp[i-1][j][k] + getDistance(x, k));
                }
            }
        }
        
        int ans = INT_MAX;
        
        for(int i=0; i<=26; ++i)
            for(int j=0; j<=26; ++j)
                ans = min(ans, dp[n-1][i][j]);
        
        return ans;
    }
};