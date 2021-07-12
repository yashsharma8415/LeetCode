class Solution {
public:
    vector<string> ans;
    vector<int> v[25];
    
    void storeStrings(int index, vector<string>& vs, string& str)
    {
        if(index == -1)
        {
            string s;
            
            s = vs.back();
            
            for(int i=vs.size()-2; i>=0; i--)
                s.append(" " + vs[i]);
            
            ans.push_back(s);
            
            return;
        }
        
        for(int x : v[index])
        {
            vs.push_back(str.substr(x + 1, index - x));
            storeStrings(x, vs, str);
            vs.pop_back();
        }
    }
    
    vector<string> wordBreak(string str, vector<string>& wordDict) 
    {
        ans.clear();
        
        int n = str.length();
        
        if (wordDict.empty())
            return ans;
        
        unordered_set<string> s;
        
        for (auto x : wordDict)
            s.insert(x);
        
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        for (int len = 1; len <= str.length(); len++)
        {
            for (int i = 0; i < len; i++)
            {
                if (dp[i] && s.find(str.substr(i, len - i)) != s.end())
                {
                    v[len - 1].push_back(i-1);
                    dp[len] = true;
                }
            }
        }
        
        // for(int i=0; i<n; i++)
        // {
        //     cout << i << " here ";
        //     for(int x : v[i])
        //         cout << x << " ";
        //     cout << endl;
        // }
        
        vector<string> vs;
        
        storeStrings(n-1, vs, str);
        
        return ans;
    }
};