class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int n = nums.size();
        int l = 0, r = n - 1;
        
        while(l < r)
        {
            int mid = (l + r + 1) / 2;
            
            if(nums[l] < nums[mid])
                l = mid;
            else
                r = mid - 1;
        }
        
        l = (l + 1) % n;
        
        return nums[l];
    }
};