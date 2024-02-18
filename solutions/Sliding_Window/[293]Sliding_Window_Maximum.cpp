#define pii pair<int, int>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        priority_queue<pii> pq;
        vector<int> maxW;
        int i = 0;
        for (int j = 0; j < nums.size(); i++) 
        {
            //push window elements to maxHeap
            for (;j - i < k; j++)
                pq.push({nums[j] , j});
            //remove maxHeap elements that are outside of the window
            while (!pq.empty() && j - pq.top().second > k)
                pq.pop();
            maxW.emplace_back(pq.top().first);
        }
        return maxW;
    }
};
