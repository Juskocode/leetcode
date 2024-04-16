class Solution {
public:
    int trap(vector<int>& height) 
    {
        int water = 0;
        int l = 0, r = height.size() - 1;
        int maxL = height[l], maxR = height[r];

        while (l < r)
        {
            if (height[l] < height[r])
            {
                l++;
                maxL = max(maxL, height[l]);
                water += maxL - height[l]; 
            }
            else
            {
                r--;
                maxR = max(maxR, height[r]);
                water += maxR - height[r];
            }
        }
        return water;  
    }
};
