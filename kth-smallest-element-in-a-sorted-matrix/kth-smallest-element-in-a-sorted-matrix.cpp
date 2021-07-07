class Solution {
public:

    int getElementsLessThanOrEqual(int num, int n, vector<vector<int>>& mat)
    {
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (mat[i][0] > num)
                return ans;

            if (mat[i][n - 1] <= num)
            {
                ans += n;
                continue;
            }

            int index = 0;

            for (int jump = n / 2; jump >= 1; jump /= 2)
            {
                while (index + jump < n && mat[i][index + jump] <= num)
                    index += jump;
            }

            ans += index + 1;
        }

        return ans;
    }

    int kthSmallest(vector<vector<int>>& mat, int k)
    {
        int n = mat.size();
        int l = mat[0][0], r = mat[n - 1][n - 1];

        while (l < r)
        {
            int mid = l + (r - l) / 2;

            int leMid = getElementsLessThanOrEqual(mid, n, mat);

            if (leMid >= k)
                r = mid;
            else
                l = mid + 1;
        }
        
        return l;
    }
};