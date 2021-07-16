class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num)
    {
        vector<vector<int>> ans;
        set<vector<int>> anss;
        
        if(num.size() <= 2)
            return ans;

        sort(num.begin(), num.end());

        for (int i = 0; i < num.size() - 2; ++i)
        {
            int reqSum = 0 - num[i], l = i + 1, r = num.size() - 1;

            while (l < r)
            {
                if (num[l] + num[r] == reqSum)
                    anss.insert({num[i], num[l], num[r]});

                if (num[l] + num[r] <= reqSum)
                    l++;
                else
                    r--;
            }
        }

        for (auto ele : anss)
            ans.push_back(ele);

        return ans;
    }
};