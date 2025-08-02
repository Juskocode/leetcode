class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int i = 0;
        unsigned total = s1.size() + s2.size() + s3.size();
        while (s1[i] && s2[i] && s3[i] && s1[i] == s2[i] && s2[i] == s3[i]) i++;
        return (i == 0) ? -1 : total - 3 * i;
    }
};