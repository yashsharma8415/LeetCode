class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int dp[amount + 5];
        fill(dp, dp + amount + 5, INT_MAX - 15);
        
        dp[0] = 0;
        
        for(int i=1; i<=amount; ++i)
        {
            for(int x : coins)
            {
                if(x > i)
                    continue;
                
                dp[i] = min(dp[i], dp[i-x] + 1);
            }
        }
        
        if(dp[amount] > 100005)
            dp[amount] = -1;
        
        return dp[amount];
    }
};