class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        int num = 0;
        stack<pair<string,int>> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]))
                num = (num * 10) + (s[i] - '0');
           else if (isalpha(s[i]))
                ans += s[i];
           else if (s[i] == '[')
            {
                st.push({ans,num});
                ans = "";
                num = 0;
            }
            else if (s[i]==']')
            {
                string tmp = ans;
                auto [cap, re] = st.top();
                for (int i = 1; i < re; i++)                
                   tmp += ans;
                ans = cap + tmp;
                st.pop();
            }  
        }
        return ans;
    }
};