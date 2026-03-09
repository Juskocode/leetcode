class Solution {
public:
    //[1*][0*] -> means that the string would be always 1's followed by 0's
    bool checkOnesSegment(string s) {
        int i = 0;
        while (s[i] == '1') i++;
        while (s[i] == '0') i++;
        return s[i] != '1';
    }
};