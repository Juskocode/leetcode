class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int i = 0;
        cout << "idx " << i << endl;
        unsigned total = s1.size() + s2.size() + s3.size();
        while (s1[i] == s2[i] && s2[i] == s3[i])
        {
            i++;
            cout << "idx " << i << endl;
            if (!s1[i] || s1[i] != s2[i] || s1[i] != s3[i])
                return total - 3 * i;
            cout << "1" << endl;
            if (!s2[i] || s2[i] != s3[i] || s2[i] != s1[i])
                return total - 3 * i;
            cout << "2" << endl;
            if (!s3[i] || s3[i] != s2[i] || s3[i] != s2[i])
                return total - 3 * i;
            cout << "3" << endl;
        }
        return -1;
    }
};