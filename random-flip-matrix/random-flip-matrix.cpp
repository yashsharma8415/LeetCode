class Solution {
public:
    
    int cnt, cols, rows;
    unordered_map<int, int> hash;
    
    Solution(int n_rows, int n_cols) 
    {
        rows = n_rows;   
        cols = n_cols;
        cnt = n_rows * n_cols;
    }
    
    vector<int> flip() 
    {
        int index = rand() % (cnt--);
        int i = hash.count(index) ? hash[index] : index;
        hash[index] = hash.count(cnt) ? hash[cnt] : cnt;
        
        return {i / cols, i % cols};
        
    }
    
    void reset() 
    {    
        cnt = rows * cols;
        hash.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */