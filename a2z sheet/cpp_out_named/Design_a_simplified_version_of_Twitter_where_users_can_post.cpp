/*
 * QUESTION:
 *
 * Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.
 *
 * Find it: https://www.google.com/search?q=Design%20a%20simplified%20version%20of%20Twitter%20where%20users%20can%20post%20tweets%2C%20follow/unfollow%20another%20user%2C%20and%20is%20able%20to
 */

// ---- write your solution below ----

class Twitter {
private:
    struct Tweet {
        int tweetId;
        int time;
        // member initializer list:
        Tweet(int id, int t) : tweetId(id), time(t) {}

        bool operator<(const Tweet& other) const {
            return time < other.time;
        }
    };

        int timestamp;
        unordered_map<int, vector<Tweet>> tweets;
        unordered_map<int, unordered_set<int>> following;

public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        timestamp++;
        tweets[userId].emplace_back(tweetId, timestamp);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;

        priority_queue<Tweet> maxHeap;

        if (tweets.find(userId) != tweets.end())
        {
            for (const auto& tweet : tweets[userId])
            {
                maxHeap.push(tweet);
            }
        }

        if (following.find(userId) != following.end())
        {
            for (int followeeId : following[userId])
            {
                if (tweets.find(followeeId) != tweets.end())
                {
                    for (const auto& tweet : tweets[followeeId])
                    {
                        maxHeap.push(tweet);
                    }
                }
            }
        }

        /* ANOTHER FORMAT:
        std::vector<int> getNewsFeed(int userId) {
            // Create the final container that will hold our ordered list of tweet IDs
            std::vector<int> feed;
            
            // Initialize our Max-Heap sorting basket (the newest tweets rise to the top automatically)
            std::priority_queue<Tweet> maxHeap;

            // --- PHASE 1A: Gather the user's own tweets directly using vector indexing ---
            if (tweets.find(userId) != tweets.end()) {
                for (int i = 0; i < tweets[userId].size(); ++i) {
                    maxHeap.push(tweets[userId][i]);
                }
            }

            // --- PHASE 1B: Gather tweets from everyone the user follows using a vector copy and index loop ---
            if (following.find(userId) != following.end()) {
                // Copy the followees set into a vector so we can use standard numerical indexing
                std::vector<int> followees(following[userId].begin(), following[userId].end());
                
                // Loop through the followees vector using a traditional index-based loop
                for (int i = 0; i < followees.size(); ++i) {
                    int followeeId = followees[i];
                    
                    // Check if that followee has posted any tweets
                    if (tweets.find(followeeId) != tweets.end()) {
                        // Loop through the followee's tweet vector using a traditional index-based loop
                        for (int j = 0; j < tweets[followeeId].size(); ++j) {
                            maxHeap.push(tweets[followeeId][j]);
                        }
                    }
                }
            }

            // --- PHASE 3: Extract up to the 10 most recent tweets using the while loop ---
            int count = 0;
            while (!maxHeap.empty() && count < 10) {
                feed.push_back(maxHeap.top().tweetId);
                maxHeap.pop();
                count++;
            }

            // Return the completed vector of up to 10 sorted tweet IDs
            return feed;
        }
        */

        int count = 0;
        while (!maxHeap.empty() && count < 10)
        {
            feed.push_back(maxHeap.top().tweetId);
            maxHeap.pop();
            count++;
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
        {
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
