class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> topOrder;
        int count = 0;
        for (const auto &pre: prerequisites)
            adj[pre[1]].push_back(pre[0]);

        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
        {
            for (const int &dest : adj[i])
                indegree[dest]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++)
        {
            if (!indegree[i])
                q.push(i);
        }

        while (!q.empty())
        {
            int n = q.front();q.pop();
            topOrder.push_back(n);
            for (const int &dest : adj[n])
            {
                indegree[dest]--;
                if (!indegree[dest])
                    q.push(dest);
            }
            count++;
        }
        if (count != numCourses)
            return {};
        return topOrder;
    }
};
