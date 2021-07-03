class Solution {
public:
    int longestMountain(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> asc(n, 1), dsc(n, 1);

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
                asc[i] += asc[i - 1];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] > nums[i + 1])
                dsc[i] += dsc[i + 1];
        }

        int ans = 0;

        for (int i = 1; i < n - 1; ++i)
        {
            if(asc[i] <= 1 || dsc[i] <= 1)
                continue;
            
            ans = max(ans, asc[i] + dsc[i] - 1);
        }

        if (ans <= 2)
            ans = 0;

        return ans;
    }
};