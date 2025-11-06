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


        unordered_set<int> users = following[userId];
        users.insert(userId);

        // Each heap element: {timestamp, {userId, tweetIndex}}
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        // Step 2: Push the most recent (last) tweet from each user into the heap
        for(int currUser : users){
            auto &tweetList = tweets[currUser];

            if(!tweetList.empty()){
                int lastTweetIndex = tweetList.size() - 1;
                int lastTweetTime = tweetList[lastTweetIndex].first;
                maxHeap.push({lastTweetTime, {currUser, lastTweetIndex}});
            }
        }

        vector<int> feed;  // Stores up to 10 most recent tweet IDs
        // Step 3: Extract the 10 most recent tweets
        while (!maxHeap.empty() && feed.size() < 10) {
            auto topTweet = maxHeap.top();
            maxHeap.pop();

            int tweetTime = topTweet.first;
            int tweetUser = topTweet.second.first;
            int tweetIndex = topTweet.second.second;

            int tweetId = tweets[tweetUser][tweetIndex].second;  
            feed.push_back(tweetId);

            if(tweetIndex > 0){
                int prevTweetTime = tweets[tweetUser][tweetIndex - 1].first;
                maxHeap.push({prevTweetTime, {tweetUser, tweetIndex - 1}});
            }
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