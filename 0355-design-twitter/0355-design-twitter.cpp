class Twitter {
private:
    int timeStamp;  
    /*
        Global counter to represent the order in which tweets are posted.
        Each new tweet gets a unique, increasing timestamp.
    */

    // ---------------------- FOLLOWING MAP ----------------------
    unordered_map<int, unordered_set<int>> following;
    /*
        Structure:
            following[followerId] = { followeeId1, followeeId2, ... }

        Example:
            following[1] = {2, 3}
            → means user 1 follows users 2 and 3
    */

    // ---------------------- TWEETS MAP ----------------------
    unordered_map<int, vector<pair<int, int>>> tweets;
    /*
        Structure:
            tweets[userId] = { {timestamp1, tweetId1}, {timestamp2, tweetId2}, ... }

        Example:
            tweets[1] = { {0, 5}, {2, 8} }
            → user 1 posted tweet 5 at time 0, and tweet 8 at time 2
    */

public:
    // ---------------------- CONSTRUCTOR ----------------------
    Twitter() {
        timeStamp = 0;
    }

    // ---------------------- POST TWEET ----------------------
    void postTweet(int userId, int tweetId) {
        /*
            Add a new tweet for the user along with a timestamp.
            Time increases with every tweet posted in the entire system.
        */
        tweets[userId].push_back({timeStamp++, tweetId});
    }

    // ---------------------- GET NEWS FEED ----------------------
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;  // Stores up to 10 most recent tweet IDs

        // Each heap element: {timestamp, {userId, tweetIndex}}
        priority_queue<pair<int, pair<int, int>>> maxHeap;

        // Step 1: Collect all users to include in the feed (self + followees)
        unordered_set<int> users = following[userId];
        users.insert(userId);

        /*
            Example:
                following[1] = {2, 3}
                → users = {1, 2, 3}
        */

        // Step 2: Push the most recent (last) tweet from each user into the heap
        for (int currUser : users) {
            auto &tweetList = tweets[currUser];

            if (!tweetList.empty()) {
                int lastTweetIndex = tweetList.size() - 1;
                int lastTweetTime = tweetList[lastTweetIndex].first;

                // Heap entry structure → {timestamp, {userId, tweetIndex}}
                maxHeap.push({lastTweetTime, {currUser, lastTweetIndex}});
            }
        }

        // Step 3: Extract the 10 most recent tweets
        while (!maxHeap.empty() && feed.size() < 10) {
            auto topElement = maxHeap.top();
            maxHeap.pop();

            int tweetTime  = topElement.first;
            int tweetUser  = topElement.second.first;
            int tweetIndex = topElement.second.second;

            int tweetId = tweets[tweetUser][tweetIndex].second;
            feed.push_back(tweetId);

            /*
                Example of heap content at this stage:
                {timestamp = 15, {userId = 2, tweetIndex = 4}}
                {timestamp = 13, {userId = 1, tweetIndex = 2}}
            */

            // Step 4: Push this user's next older tweet (if exists)
            if (tweetIndex > 0) {
                int prevTweetTime = tweets[tweetUser][tweetIndex - 1].first;
                maxHeap.push({prevTweetTime, {tweetUser, tweetIndex - 1}});
            }
        }

        return feed;
    }

    // ---------------------- FOLLOW ----------------------
    void follow(int followerId, int followeeId) {
        // A user cannot follow themselves
        if (followerId == followeeId) return;

        following[followerId].insert(followeeId);
    }

    // ---------------------- UNFOLLOW ----------------------
    void unfollow(int followerId, int followeeId) {
        if (following.count(followerId)) {
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
 * 
 * Algorithm Explanation:
 * 
 * The optimized getNewsFeed uses a K-way merge algorithm:
 * 1. Instead of pushing ALL tweets into heap, only push the most recent tweet from each user
 * 2. Extract the most recent tweet overall (heap top)
 * 3. Push that user's next tweet into the heap
 * 4. Repeat until we have 10 tweets or no more tweets available
 * 
 * This is much more efficient than the naive approach:
 * - Naive: O(N × T × log(N × T)) time, O(N × T) space
 * - Optimized: O(N + 10 × log N) time, O(N) space
 * 
 * Where N = number of users in feed, T = average tweets per user
 */