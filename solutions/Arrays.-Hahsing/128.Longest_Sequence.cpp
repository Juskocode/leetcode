class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
            unordered_set<int> st;
            for (int num : nums)
                st.insert(num);
            int longest = 0;
            for (int num : nums)
            {
                if (st.find(num + 1) == st.end())
                {
                    int key = num;
                    int len = 1;
                    while (st.find(key - 1) != st.end())
                    {
                        key--;
                        len++;
                    }
                    longest = max(longest, len);
                }
            }
            return longest;
    }
};
