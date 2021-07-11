class Solution {
public:
    bool isPossible(vector<int>&arr, int m, int mid)
    {
        int part = 1, sum = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];

            if (sum > mid)
            {
                sum = arr[i];
                part++;

                if (part > m)
                    return false;
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int m)
    {
        int low = 0, high = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            low = max(low, nums[i]);
            high += nums[i];
        }

        while (low < high)
        {
            int mid = (low + high) / 2;

            if (isPossible(nums, m, mid))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};