class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // check comutativity
        if (str1 + str2 != str2 + str1)
            return "";
        unsigned g = gcd(str1.size(), str2.size());
        return str1.substr(0, g);
    }
};