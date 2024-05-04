class Solution {
public:
    int openLock(vector<string>& deadends, string target) 
    {
        unordered_set<string> v(deadends.begin(), deadends.end());
        if (v.find("0000") != v.end())
            return -1;
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        v.insert("0000");

        while (!q.empty())
        {
            auto [state, moves] = q.front();q.pop();
            
            if (state == target)
                return moves;

            for (int i = 0; i < 4; i++)
            {
                for (int d : {-1, 1})
                {
                    string newState = state;
                    int transition = (state[i] -'0' + d + 10) % 10;
                    newState[i] = '0' + transition;

                    if (v.find(newState) == v.end())
                    {
                        q.push({newState, moves + 1});
                        v.insert(newState);
                    }
                }
            }
        }
        return -1;
    }
};
