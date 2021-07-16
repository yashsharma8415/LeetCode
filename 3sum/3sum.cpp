class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num)
    {
        vector<vector<int>> ans;

        if (num.size() <= 2)
            return ans;

        sort(num.begin(), num.end());

        int reqSum, l, r;

        for (int i = 0; i < num.size() - 2; ++i)
        {
            if (i > 0 && num[i] == num[i - 1])
                continue;

            reqSum = 0 - num[i], l = i + 1, r = num.size() - 1;

            while (l < r)
            {
                if (num[l] + num[r] == reqSum)
                {
                    ans.push_back({num[i], num[l], num[r]});

                    l++;
                    r--;

                    while (l < r && num[l] == num[l - 1])
                        l++;

                    while (l < r && num[r] == num[r + 1])
                        r--;
                }
                else if (num[l] + num[r] <= reqSum)
                    l++;
                else
                    r--;
            }
        }

        return ans;
    }
};