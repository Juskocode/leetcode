class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int na = nums1.size(), nb = nums2.size();
        int n = na + nb;

        if (n % 2)
            return solve(nums1, nums2, n / 2, 0, na - 1, 0, nb - 1);

        return  1.0 * (solve(nums1, nums2, n / 2 - 1, 0, na - 1, 0, nb - 1) +
                solve(nums1, nums2, n / 2, 0, na - 1, 0, nb - 1)) / 2;
       }
    
    int solve(vector<int>& nums1, vector<int>& nums2, int k, int l1, int r1, int l2, int r2)
    {
        if (r1 < l1)
            return nums2[k - l1];
        if (r2 < l2)
            return nums1[k - l2];
        
        int m1 = l1 + (r1 - l1) / 2, m2 = l2 + (r2 - l2) / 2;

        if (m1 + m2 < k)
        {
            if (nums1[m1] > nums2[m2])
                return solve(nums1, nums2, k, l1, r1, m2 + 1, r2);
            return solve(nums1, nums2, k, m1 + 1, r1, l2, r2);
        }
        else
        {
            if (nums1[m1] > nums2[m2])
                return solve(nums1, nums2, k, l1, m1 - 1, l2, r2);
            return solve(nums1, nums2, k, l1, r1, l2, m2 - 1);
        }
        return -1;
    }
};