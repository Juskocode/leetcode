class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1, s2;
        for (const int &v : nums1)
            s1.insert(v);
        for (const int &v : nums2)
        {
            if (s1.find(v) != s1.end())
                s1.erase(v);
            s2.insert(v);        
        }
        for (const int &v : nums1)
            if (s2.find(v) != s2.end())
                s2.erase(v);
        vector<vector<int>> v;
        v.push_back(vector<int> (s1.begin(), s1.end()));
        v.push_back(vector<int> (s2.begin(), s2.end()));
        return v;
    }
};