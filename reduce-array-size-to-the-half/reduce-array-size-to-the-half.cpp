class Solution {
public:
    int minSetSize(vector<int>& arr) 
    {
        map<int, int> mp;
        int len = arr.size(), ans = 0, sum = 0;
        vector<int> v;
        
        for(int x : arr)
            mp[x]++;
        
        for(auto ele : mp)
            v.push_back(ele.second);
        
        sort(v.begin(), v.end(), greater<int>());
        
        for(int x : v)
        {
            sum += x;
            ans++;
            
            if(sum >= len / 2)
                break;
        }
        
        return ans;
    }
};