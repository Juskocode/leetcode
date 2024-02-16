// not the best aproach, optimal is very smillar bur instead of getting the hole word
// it searches for each char and creates a new subword each iteretion
// this solution creates a graph and bfs the graph for the min cost only
// the main complexity comes from creating the adjency list
// T = O(N² * L + |V + E|)  where L is length of the words
// optimal solution is better by a small marging
// T = O(|V + E| * L * d) where d is the length of the shortest sequence
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

    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        if (find(wordList.begin(), wordList.end(), beginWord) == wordList.end())
            wordList.push_back(beginWord);
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return (0);
        int n = (int)wordList.size();
        unordered_map<string, vector<string>> adj;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (i != j && isAdj(wordList[i], wordList[j]))
                {
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        unordered_map<string, int> distance;
        for (const string& word : wordList)
            distance[word] = INT_MAX;

        distance[endWord] = 0;

        queue<string> q;
        q.push(endWord);

        while (!q.empty()) {
            string w = q.front();
            q.pop();

            for (const string& nw : adj[w]) 
            {
                if (distance[nw] == INT_MAX) 
                {
                    distance[nw] = distance[w] + 1;
                    q.push(nw);
                }
            }
        }

        return (distance[beginWord] == INT_MAX) ? 0 : distance[beginWord] + 1;
    }
};
