class Solution {
public:
    int minCut(string s) 
    {
        int n = s.length();
        
        bool isPalindrome[n][n];
        int dp[n];
        
        for(int len=1; len<=n; ++len)
        {
            for(int l=0; l+len<=n; ++l)
            {
                int r = l + len - 1;
                
                if(len == 1)
                    isPalindrome[l][r] = true;
                else if(len == 2)
                    isPalindrome[l][r] = (s[l] == s[r]);
                else
                    isPalindrome[l][r] = isPalindrome[l+1][r-1] && (s[l] == s[r]);
            }
        }
        
        for(int i=0; i<n; ++i)
        {
            dp[i] = INT_MAX;
            
            for(int j=i; j>=0; --j)
            {
                if(!isPalindrome[j][i])
                    continue;
                
                dp[i] = min(dp[i], (j == 0 ? 0 : dp[j-1]) + 1);
            }
        }
        
        return dp[n-1] - 1;
    }
};