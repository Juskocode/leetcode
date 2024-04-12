class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        int visited [127] = {0}, i = 0;

        while (s[i])
        {
            visited[s[i]]++;
            i++;
        }
        i = 0;
        while (t[i])
        {
            visited[t[i]]--;
            i++;
        }
        for (int i = 0; i < 127; i++)
        {
            if (visited[i])
                return (false);
        }
        return (true);
    }
};
