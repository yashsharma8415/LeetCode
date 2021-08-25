class Solution {
public:
    bool judgeSquareSum(int c) 
    {
        int i = floor(sqrt(c));
        
        if (i * i == c)
            return true;
        else 
        {
            int j = 1;
            
            while (j <= i) 
            {
                if (i * i * 1ll + j * j == (long long)c)
                    return true;
                else if (i * i * 1ll + j * j < (long long)c)
                    j++;
                else
                    i--;
            }
        }

        return false;    
    }
};