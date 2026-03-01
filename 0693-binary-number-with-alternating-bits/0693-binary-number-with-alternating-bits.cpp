class Solution {
public:
    bool hasAlternatingBits(int n) {
        cout << (1431655765 >> (int)(31 - log2(n))) << endl;
        return n == (1431655765 >> (int)(31 - log2(n))) || n <= 2;
    }
};