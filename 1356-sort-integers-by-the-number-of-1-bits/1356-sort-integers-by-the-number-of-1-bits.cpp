class Solution {
public:
    // 1001
    // LB -> if its 1 (1001 & 0001) -> 1
    // 0100 -> if its 1 (0100 & 0001) -> 0
    // 0010 -> if its 1 (0010 & 0001) -> 0
    // 0001 -> if its 1 (0001 & 0001) -> 1
    // 6 -> 0110
    static int computeNbits(const int &val) {
        int p = val, b = 0;
        while (p) {
            if (p & 1)
                b++;
            p >>= 1;
        }
        return b;   
    }

    static bool cmp(const int &a, const int &b) {
        if (computeNbits(a) == computeNbits(b))
            return a < b;
        return computeNbits(a) < computeNbits(b);
    }

    vector<int> sortByBits(vector<int>& arr) {
       
        sort(arr.begin(), arr.end(), cmp);
        
        return arr;
    }
};