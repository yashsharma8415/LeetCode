class Solution {
public:
    int singleNonDuplicate(vector<int>& num)
    {
        int n = num.size();
        int l = 0, r = n - 1;

        while (l < r)
        {
            int curSize = (r - l + 1) / 2, mid = (l + r) / 2;

            if (num[mid] != num[mid - 1] && num[mid] != num[mid + 1])
                return num[mid];
            if (num[mid] == num[mid - 1])
            {
                if (curSize % 2 == 0)
                    r = mid - 2;
                else
                    l = mid + 1;
            }
            else
            {
                if (curSize % 2 == 0)
                    l = mid + 2;
                else
                    r = mid - 1;
            }
        }

        return num[l];
    }
};