class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        unsigned max_v = *(max_element(candies.begin(), candies.end()));
        vector<bool> v(candies.size());
        for (int i = 0; i < candies.size(); i++)
            if (candies[i] + extraCandies >= max_v)
                v[i] = 1;
        return v;
    }
};