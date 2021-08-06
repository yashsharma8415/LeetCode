class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int n = nums.size();
        int dppos[n], dpneg[n], ans = 0;
        
        if(n == 1)
            return nums[0];
        
        for(int i=0; i<n; ++i)
        {
            if(i == 0)
            {
                if(nums[i] >= 0)
                {
                    dppos[i] = nums[i];
                    dpneg[i] = 0;
                }
                else
                {
                    dppos[i] = 0;
                    dpneg[i] = nums[i];
                }
            }
            else
            {
                if(nums[i] >= 0)
                {
                    dppos[i] = max(dppos[i-1] * nums[i], nums[i]);
                    dpneg[i] = dpneg[i-1] * nums[i];
                }
                else
                {
                    dppos[i] = dpneg[i-1] * nums[i];
                    dpneg[i] = min(dppos[i-1] * nums[i], nums[i]);
                }
            }
            
            ans = max({ans, dppos[i], dpneg[i]});
        }
        
        return ans;
    }
};