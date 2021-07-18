class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size(), n = matrix[0].size();
        
        if(target < matrix[0][0] || target > matrix[m-1][n-1])
            return false;
        
        int l = 0, r = m-1;
        
        while(l < r)
        {
            int mid = (l + r) / 2;
            
            if(matrix[mid][n-1] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        
        int row = l;
        
        l = 0, r = n - 1;
        
        while(l < r)
        {
            int mid = (l + r) / 2;
            
            if(matrix[row][mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        
        int col = l;
        
        if(matrix[row][col] == target)
            return true;
        else
            return false;
    }
};