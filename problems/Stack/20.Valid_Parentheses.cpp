class Solution {
unordered_map<char, char> brackets = {{'(', ')'},
                                      {'[',']'},
                                      {'{','}'}
                                     };
public:
    bool isValid(string s) 
    {
        stack<char> br;

        for (const char c : s)
        {
            if (brackets.count(c))
                br.push(c);
             else 
            { 
                if (br.empty() || brackets[br.top()] != c)
                    return false;
                br.pop();
            }
        }
        return br.empty();
    }
};
