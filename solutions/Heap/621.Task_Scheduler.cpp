class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        int Freq[26] = {0};

        for (auto & c : tasks)
            Freq[c -'A']++;

        sort(Freq, Freq + 26);

        int count = Freq[25], slots = (--count) * n;
        for (int i = 0; i < 25; i++)
            slots -= min(Freq[i], count);
        
        return (slots > 0) ? tasks.size() + slots : tasks.size();
    }
};
