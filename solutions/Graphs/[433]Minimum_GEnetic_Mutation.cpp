class Solution {
public:
bool isAdj(const string& s1, const string& s2)
    {
        int diffCount = 0;

        for (int i = 0; i < (int)s1.size(); ++i)
        {
            if (s1[i] != s2[i])
                ++diffCount;
            if (diffCount > 1)
                return false;
        }
        return true;
    }
    int minMutation(string startGene, string endGene, vector<string>& bank)
    {
        int n = bank.size() + 1, cost = 0;
        unordered_map<string, vector<string>> adj;
        unordered_map<string, bool> visited;
        bank.push_back(startGene);

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                string l = bank[i], r = bank[j];
                if (isAdj(l, r))
                {
                    adj[bank[i]].push_back(bank[j]);
                    adj[bank[j]].push_back(bank[i]);
                }
            }
        }
        for (const string &gene : bank)
            visited[gene] = false;
        visited[startGene] = true;
        queue<string> q;
        q.push(startGene);

        while (!q.empty())
        {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++)
            {
                string v = q.front();q.pop();

                if (v == endGene)
                    return cost;

                for (const string & e : adj[v])
                {
                    if (!visited[e])
                    {
                        visited[e] = true;
                        q.push(e);
                    }
                }
            }
            cost++;
        }
        return -1;
    }
};
