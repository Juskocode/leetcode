class Solution {
public:
    bool isSubstring(const string &a, const string &b)
    {
        for (int i = 0; i < b.size(); i++)
        {
            int j = 0;
            while (b[i + j] == a[j] && j < a.size() && (i + j) < b.size())
                j++;
            if (j == a.size())
                return true;
        }
        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
        vector<string> m;

        for (int i = 0 ; i < words.size(); i++)
        {
            for (int j = 0; j < words.size(); j++)
            {
                if (i == j) continue;
                if (words[j].find(words[i])!=-1)
                {
                    m.push_back(words[i]);
                    break;
                }
            }
        }
        return m;
    }
};