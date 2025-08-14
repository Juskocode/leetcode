class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> heap;

        for (int i = 0; i < n; i++)
        {
            if (heap.size() == k && heap.top() <= nums[i])
                heap.pop();
            if (heap.size() < k)
                heap.push(nums[i]);
        }
        return heap.top();
    }
};