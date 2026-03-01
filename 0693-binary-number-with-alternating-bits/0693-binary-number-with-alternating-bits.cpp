class Solution {
public:
    bool hasAlternatingBits(int n) {
        return n == (1431655765 >> (int)(31 - log2(n))) || n <= 2;
    }
};