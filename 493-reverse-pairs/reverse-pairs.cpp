class Solution {
    long long mergeSort(vector<int>& nums,
                        vector<int>& temp,
                        int low,
                        int high) {

        if (low >= high)
            return 0;

        int mid = low + (high - low) / 2;

        long long cnt = 0;

        cnt += mergeSort(nums, temp, low, mid);
        cnt += mergeSort(nums, temp, mid + 1, high);

        // Count reverse pairs
        int j = mid + 1;

        for (int i = low; i <= mid; i++) {
            while (j <= high &&
                   (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }

            cnt += j - (mid + 1);
        }

        // Merge
        int i = low;
        j = mid + 1;
        int k = low;

        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j])
                temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++];
        }

        while (i <= mid)
            temp[k++] = nums[i++];

        while (j <= high)
            temp[k++] = nums[j++];

        for (int p = low; p <= high; p++)
            nums[p] = temp[p];

        return cnt;
    }

public:
    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size());
        return mergeSort(nums, temp, 0, nums.size() - 1);
    }
};