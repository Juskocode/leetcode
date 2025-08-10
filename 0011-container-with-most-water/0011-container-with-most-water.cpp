class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, maxA = 0, currA;

        while (l <= r)
        {
            //cout << height[l] << " " << height[r] << " " << (r - l) << endl;
            maxA = max(min(height[l], height[r]) * (r - l), maxA);
            if (height[l] <= height[r])
                l++;
            else
                r--;
        }
        return maxA;
    }
};