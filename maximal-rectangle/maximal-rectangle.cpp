class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        if(matrix.empty())
            return 0;
        
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        
        vector<vector<int>> prefixSum(n, vector<int>(m, 0)), dp(m, vector<int>(m, 0));
        
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                if(j == 0)
                    prefixSum[i][j] = matrix[i][j] - '0';
                else
                    prefixSum[i][j] = prefixSum[i][j-1] + matrix[i][j] - '0';
            }
        }
        
        for(int i=0; i<n; ++i)
        {
            for(int l=0; l<m; ++l)
            {
                for(int r=l; r<m; ++r)
                {
                    if(prefixSum[i][r] - (l == 0 ? 0 : prefixSum[i][l - 1]) == (r - l + 1))
                        dp[l][r] = dp[l][r] + 1;
                    else
                        dp[l][r] = 0;
                    
                    ans = max(ans, dp[l][r] * (r - l + 1));
                }
            }
        }
        
        return ans;
    }
};