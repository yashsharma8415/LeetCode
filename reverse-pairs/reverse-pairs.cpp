class Solution {
public:
    int mergeSort(int arr[], int array_size)
    {
        int temp[array_size];
        return _mergeSort(arr, temp, 0, array_size - 1);
    }

    int _mergeSort(int arr[], int temp[], int left, int right)
    {
        int mid, inv_count = 0;

        if (right > left)
        {
            mid = (right + left) / 2;

            inv_count += _mergeSort(arr, temp, left, mid);
            inv_count += _mergeSort(arr, temp, mid + 1, right);

            inv_count += merge(arr, temp, left, mid + 1, right);
        }

        return inv_count;
    }

    int merge(int arr[], int temp[], int left, int mid, int right)
    {
        int i, j, k;
        int inv_count = 0;

        i = left;
        j = mid;
        k = left;

        for (int i = mid; i <= right; ++i)
        {
            long long temp = 2ll * arr[i];
            
            if(temp < INT_MIN)
                inv_count += mid - left;
            else if(temp <= INT_MAX && temp >= INT_MIN)
                inv_count += (arr + mid) - upper_bound(arr + left, arr + mid, 2 * arr[i]);
        }

        while ((i <= mid - 1) && (j <= right))
        {
            if (arr[i] <= arr[j])
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];
        }

        while (i <= mid - 1)
            temp[k++] = arr[i++];

        while (j <= right)
            temp[k++] = arr[j++];

        for (i = left; i <= right; i++)
            arr[i] = temp[i];

        return inv_count;
    }

    int reversePairs(vector<int>& nums)
    {
        int n = nums.size();

        int arr[n];

        for (int i = 0; i < n; ++i)
            arr[i] = nums[i];

        return mergeSort(arr, n);
    }
};