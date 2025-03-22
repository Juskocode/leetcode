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
        set<string> m;

        for (int i = 0 ; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                if (isSubstring((words[i].size() < words[j].size()) ? words[i] : words[j],
                     (words[i].size() >= words[j].size()) ? words[i] : words[j]))
                    m.insert((words[i].size() < words[j].size()) ? words[i] : words[j]);
            }
        }
        vector<string> res(m.begin(), m.end());
        return res;
    }
};