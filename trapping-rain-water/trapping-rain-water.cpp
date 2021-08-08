class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size(), ans = 0;
        int maxir[n], maxil[n];
        
        for(int i=n-1; i>=0; --i)
            maxir[i] = max(height[i], (i == n-1 ? 0 : maxir[i+1]));
        
        for(int i=0; i<n-1; ++i)
        {
            if(maxir[i+1] >= height[i])
            {
                int j;
                
                for(j=i+1; j<n; ++j)
                {
                    if(height[j] >= height[i])
                        break;
                    
                    ans += height[i] - height[j];
                    height[j] = height[i];
                }
                
                i = j - 1;
            }
            
            // cout << i << " " << ans << endl;
        }
        
        for(int i=0; i<n; ++i)
            maxil[i] = max(height[i], (i == 0 ? 0 : maxil[i-1]));
        
        for(int i=n-1; i>0; --i)
        {
            if(maxil[i-1] >= height[i])
            {
                int j;
                
                for(j=i-1; j>=0; --j)
                {
                    if(height[j] >= height[i])
                        break;
                    
                    ans += height[i] - height[j];
                    height[j] = height[i];
                }
                
                i = j + 1;
            }
            
            // cout << i << " " << ans << endl;
        }
        
        return ans;
    }
};