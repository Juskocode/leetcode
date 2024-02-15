
class Solution {
public:
    //kahn's algo
    //Compute in indegree of each vertex, and push the the queue
    // only the vertex with 0 indegree
    // performe a BFS and decrease remove the edge beteween the node and the dest
    // push to the queue the dest if after removing the indegree in 0
    // check if all vertex were visites, if not the graph as cycles
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (const auto &prereq : prerequisites)
            adj[prereq[0]].push_back(prereq[1]);
        
        int count = 0;
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

            for (const int &dest : adj[n])
            {
                indegree[dest]--;
                if (!indegree[dest])
                    q.push(dest);
            }
            count++;
        }
        //graph as cycles cannot find any topological order
        if (count != numCourses)
            return (false);
        //graph as a topological order
        return (true);
    }
};
