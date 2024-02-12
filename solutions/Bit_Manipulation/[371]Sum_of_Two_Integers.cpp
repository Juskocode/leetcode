class Solution {
public:
    int getSum(int a, int b) 
    {
        int carry = 1;
        while(b && carry)
        {
            carry = a & b;
            a ^= b;
            b = carry << 1;
        }
        return (a);
    }
};
