class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if(nums1.size() > nums2.size())
            nums1.swap(nums2);
        
        int n1 = nums1.size(), n2 = nums2.size();
        
        bool isEven = false;
        
        if((n1 + n2) % 2 == 0)
            isEven = true;
        
        if(n1 == 0)
        {
            if(isEven)
                return (nums2[n2/2 - 1] + nums2[n2/2]) / 2.0;
            else 
                return nums2[n2/2] * 1.0;
        }
        else if(n2 == 0)
        {
            if(isEven)
                return (nums1[n1/2 - 1] + nums1[n1/2]) / 2.0;
            else 
                return nums1[n1/2] * 1.0;
        }
        
        int l = 0, r = n1;
        
        while(l <= r)
        {
            int partx = (l + r) / 2;
            int party = (n1 + n2 + 1) / 2 - partx;
            
            int x1 = (partx == 0) ? INT_MIN : nums1[partx - 1];
            int x2 = (partx == n1) ? INT_MAX : nums1[partx];
            int y1 = (party == 0) ? INT_MIN : nums2[party - 1];
            int y2 = (party == n2) ? INT_MAX : nums2[party];
            
            if(x1 <= y2 && y1 <= x2)
            {
                if(isEven)
                    return (max(x1, y1) + min(x2, y2)) / 2.0;
                else
                    return max(x1, y1) * 1.0;
            }
            else if(x1 <= y2)
                l = partx + 1;
            else
                r = partx - 1;
        }
        
        return 0.0;
    }
};