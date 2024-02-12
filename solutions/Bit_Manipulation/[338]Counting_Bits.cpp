class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n + 1);

        //0 -> 0 bits
        bits[0] = 0;

        // the current i as the same number of bits of i / 2 + the Last bit, that is if the 
        // the number is ODD or EVEN adds one bit or not
        // using a 1-D dp we can deacrease the time compexity of this problem be finding a smaller
        // problem first that is the realation between the current bits of i and i / 2
        for (int i = 1; i <= n; i++)
            bits[i] = bits[i / 2] + (i & 1);
        
        return (bits);
    }
};
