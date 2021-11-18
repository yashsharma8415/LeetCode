#define LIM 505

class Solution {
public:
    
    int maxSatisfaction(vector<int>& sat) 
    {
        int dp[LIM][LIM];
        int n = sat.size();  
        
        sort(sat.begin(), sat.end());
        
        dp[0][0] = 0;
        
        for(int i=1; i<=n; ++i)
        {
            dp[i][0] = 0;
            
            for(int j=1; j<=i; ++j)
            {
                if(i == j)
                    dp[i][j] = dp[i-1][j-1] + sat[i-1] * j;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + sat[i-1] * j);
            }
        }
        
        int ans = 0;
        
        for(int i=0; i<=n; ++i)
            ans = max(ans, dp[n][i]);
        
        return ans;
    }
};