class TaskManager {
public:

    unordered_map<int, pair<int, int>> tasksCache;
    priority_queue<pair<int, int>> taskmngr;

    TaskManager(vector<vector<int>>& tasks) {
        for (const auto &task : tasks) {
            taskmngr.emplace(task[2], task[1]);
            tasksCache[task[1]] = {task[2], task[0]};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskmngr.emplace(priority, taskId);
        tasksCache[taskId] = {priority, userId};
    }
    
    void edit(int taskId, int newPriority) {
        if (tasksCache.find(taskId) != tasksCache.end()) {
            tasksCache[taskId].first = newPriority;
            taskmngr.emplace(newPriority, taskId);
        }
    }
    
    void rmv(int taskId) {
        tasksCache.erase(taskId);
    }
    
    int execTop() {
        while (!taskmngr.empty()) {
            auto [w, id] = taskmngr.top();taskmngr.pop();

            if (tasksCache.find(id) != tasksCache.end() && tasksCache[id].first == w) {
                int userId = tasksCache[id].second;
                tasksCache.erase(id);
                return userId;
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */