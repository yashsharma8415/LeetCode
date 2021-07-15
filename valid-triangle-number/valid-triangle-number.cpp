class Solution {
public:
    int triangleNumber(vector<int>& nums)
    {
        vector<int> num;
        int ans = 0;

        for (int x : nums)
        {
            if (x > 0)
                num.push_back(x);
        }

        sort(num.begin(), num.end());

        int n = num.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                auto itr = lower_bound(num.begin(), num.end(), num[i] + num[j]);
                ans += (itr - num.begin() - j - 1);
            }
        }

        return ans;
    }
};