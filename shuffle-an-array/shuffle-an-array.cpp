class Solution {
public:
    vector<int> onum, num;
    
    Solution(vector<int>& nums) 
    {
        onum = nums;
        num = nums;
        
        srand (time(NULL));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() 
    {
        num = onum;
        return num;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() 
    {
        for (int i = num.size() - 1; i > 0; i--)
        {
            int j = rand() % (i + 1);

            swap(num[i], num[j]);
        }    
        
        return num;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */