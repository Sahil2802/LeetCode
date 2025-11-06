class Twitter {
private:
    int timeStamp;
    unordered_map<int , unordered_set<int>> following;
    unordered_map<int , vector<pair<int, int>>> tweets;

public:
    Twitter() {
        timeStamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> users;
        users.push_back(userId);
        if(following.count(userId)){
            for(int followee : following[userId]){
                users.push_back(followee);
            }
        }

        priority_queue<pair<int, int>> maxHeap;

        for(int u : users){
            for(auto &tweet : tweets[u]){
                maxHeap.push(tweet);
            }
        } 

        vector<int> feed;
        int count = 0;
        while(!maxHeap.empty() && count < 10){
            int tweet = maxHeap.top().second;
            feed.push_back(tweet);
            maxHeap.pop();
            count++;
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(following.count(followerId)){
            following[followerId].erase(followeeId);
        }
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