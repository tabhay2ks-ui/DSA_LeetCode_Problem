class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; // Pointer for valid elements in nums1
        int j = n - 1; // Pointer for nums2
        int k = m + n - 1; // Pointer for the last position in nums1

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // Copy any remaining elements from nums2 (if any)
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};