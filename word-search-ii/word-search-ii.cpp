class Solution {
public:
    vector<vector<char>> board;
    unordered_set<string> s, anss;
    string str;
    bool visited[15][15];
    int n, m;
    
    void dfs(int r, int c)
    {        
        if(str.length() > 10 || visited[r][c])
            return;
        
        visited[r][c] = true;
        str.push_back(board[r][c]);
        
        if(s.count(str))
            anss.insert(str);
        
        if(r+1 < m)
            dfs(r+1, c);
        
        if(r-1 >= 0)
            dfs(r-1, c);
        
        if(c+1 < n)
            dfs(r, c+1);
        
        if(c-1 >= 0)
            dfs(r, c-1);
        
        visited[r][c] = false;
        str.pop_back();
    }
    
    vector<string> findWords(vector<vector<char>>& _board, vector<string>& words) 
    {
        str = "";
        board = _board;
        memset(visited, false, sizeof(visited));
        
        for(auto ele : words)
            s.insert(ele);
        
        m = board.size(), n = board[0].size();
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                dfs(i, j);
            }
        }
        
        vector<string> ans;
        
        for(auto ele : anss)
            ans.push_back(ele);
        
        return ans;
    }
};