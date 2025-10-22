class Solution {
public:
    int finalValueAfterOperations(vector<string>& op) {
        int res = 0;

        for (int i = 0; i < op.size(); i++) 
        {
            if (op[i][0] == '+' || op[i][0] == '-')
            {
                if (op[i][0] == '+')
                    res += 1;
                else
                    res -= 1;
            }
            else if (op[i][1] == '+')
                res += 1;
            else
                res -= 1;
        }
        return res;
    }
};