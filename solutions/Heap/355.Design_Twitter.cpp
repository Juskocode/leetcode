class Twitter {
public:
    unordered_map<int, unordered_set<int>> following;
    vector<pair<int, int>> feed;
    Twitter() 
    {
        
    }
    
    void postTweet(int userId, int tweetId) 
    {
        feed.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        vector<int> mostRecentUserFeed;
        for (int i = feed.size() - 1; i >= 0 && mostRecentUserFeed.size() < 10; --i)
        {
            auto& [user, tweet] = feed[i];
            if (userId == user || (following[userId].contains(user)))
                mostRecentUserFeed.push_back(tweet);
        }
        return mostRecentUserFeed;
    }
    
    void follow(int followerId, int followeeId)
    {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) 
    {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
