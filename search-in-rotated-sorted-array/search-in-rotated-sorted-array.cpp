class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int n = nums.size();

        int l = 0, r = n - 1;

        while (l < r)
        {
            int mid = (l + r) / 2;

            if (nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid;
        }

        int rot = l;

        l = 0, r = n - 1;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            int realmid = (mid + rot) % n;

            if (nums[realmid] == target)
                return realmid;

            if (nums[realmid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return -1;
    }
};