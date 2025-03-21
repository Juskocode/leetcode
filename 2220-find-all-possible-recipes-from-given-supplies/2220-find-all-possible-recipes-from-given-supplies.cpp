class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies)
    {
        unordered_set<string> avaible;
        unordered_map<string, int> recipe_id;
        unordered_map<string, vector<string>> adj;
        vector<int> ind(recipes.size(), 0);

        for (const auto & sp : supplies)
            avaible.insert(sp);
        
        for (int i = 0; i < recipes.size(); i++)
            recipe_id[recipes[i]] = i;

        for (int i = 0; i < recipes.size(); i++)
        {
            for (const auto & dep : ingredients[i])
            {
                if (!avaible.count(dep))
                {
                    adj[dep].push_back(recipes[i]);
                    ind[i]++;
                }
            }
        }

        queue<int> q;
        for (int i = 0; i < recipes.size(); i++)
            if (!ind[i])
                q.push(i);

        vector<string> top;
        while (!q.empty())
        {
            int id = q.front(); q.pop();
            string re = recipes[id];
            top.push_back(re);

            if (!adj.count(re)) continue;

            for (const auto &dep : adj[re])
            {
                if (!--ind[recipe_id[dep]])
                    q.push(recipe_id[dep]);
            }
        }
        return top;
    }
};