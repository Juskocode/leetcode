class Solution {
public:
    bool is_particionable(string sq, int n) 
    {
        if (sq == "" && !n) return true;

        if (n < 0) return false;

        for (int i = 0; i < sq.size(); i++)
        {
            string left = sq.substr(0, i + 1);
            string right = sq.substr(i + 1);
            
            if (is_particionable(right, n - stoi(left))) return true;
        }
        return false;
    }
    int punishmentNumber(int n) 
    {
        int sum = 0;

        for (int i = 1; i <= n; i++)
        {
            int squared = i * i;
            if (is_particionable(to_string(squared), i))
                sum += squared;
        }
        return sum;
    }
};
