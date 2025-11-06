class Twitter {
private:
    int timeStamp;  // Global counter to track tweet posting order
    unordered_map<int, unordered_set<int>> following;  // Maps userId to set of followees
    unordered_map<int, vector<pair<int, int>>> tweets;  // Maps userId to list of (timestamp, tweetId) pairs

public:
    // Constructor: Initialize timestamp to 0
    Twitter() {
        timeStamp = 0;
    }
    
    // Post a new tweet by a user
    // Stores tweet with current timestamp and increments timestamp
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }
    
    // Retrieve the 10 most recent tweets in the user's news feed
    // Includes tweets from the user and all their followees
    vector<int> getNewsFeed(int userId) {
        // Step 1: Collect all users whose tweets should appear in feed
        vector<int> users;
        users.push_back(userId);  // Include user's own tweets
        
        // Add all followees if user follows anyone
        if(following.count(userId)){
            for(int followee : following[userId]){
                users.push_back(followee);
            }
        }

        // Step 2: Collect all tweets from relevant users into max heap
        // Max heap ordered by timestamp (most recent first)
        priority_queue<pair<int, int>> maxHeap;

        for(int u : users){
            for(auto &tweet : tweets[u]){
                maxHeap.push(tweet);  // Push (timestamp, tweetId) pair
            }
        } 

        // Step 3: Extract top 10 most recent tweets
        vector<int> feed;
        int count = 0;
        while(!maxHeap.empty() && count < 10){
            int tweet = maxHeap.top().second;  // Get tweetId (second element of pair)
            feed.push_back(tweet);
            maxHeap.pop();
            count++;
        }
        return feed;
    }
    
    // Follower starts following a followee
    // Prevents self-following
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;  // Can't follow yourself
        following[followerId].insert(followeeId);
    }
    
    // Follower unfollows a followee
    // Only executes if follower has a following list
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