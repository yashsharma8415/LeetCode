class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int dp[n];
        dp[0] = 0;
        
        for(int i=1; i<n; ++i)
        {
            dp[i] = dp[i-1];
            
            for(int j=i-1; j>=0; --j)
            {
                dp[i] = max(dp[i], prices[i] - prices[j] + (j-2 >= 0 ? dp[j-2] : 0));
            }
        }
        
        return dp[n-1];
    }
};