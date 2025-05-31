class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), total_gas = 0, total_cost = 0;
        int curr_gas = 0, start = 0;

        for (int i = 0; i < n; i++)
        {
            total_gas += gas[i];
            total_cost += cost[i];

            curr_gas += gas[i] - cost[i];
            if (curr_gas < 0)
            {
                start = i + 1;
                curr_gas = 0;
            }
        }
        return (total_gas < total_cost) ? -1 : start;
    }
};