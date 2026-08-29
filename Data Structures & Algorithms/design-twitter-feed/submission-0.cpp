class Twitter {
public:
    unordered_map<int,unordered_set<int>> follows;
    unordered_map<int,vector<pair<int,int>>> tweetmap;
    int time;
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetmap[userId].push_back({time,tweetId});
        time++;
    }
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int,int,int>> pq;
        vector<int> users;
        users.push_back(userId);
        for(auto u:follows[userId]){
           users.push_back(u);
        }
        for(auto u:users){
           auto &tweets=tweetmap[u];
           if(!tweets.empty()){
              int index=tweets.size()-1;
              pq.push({tweets[index].first,u,index});
           }
        }
        vector<int> ans;
        while(!pq.empty()&&ans.size()<10){
            auto [time,userid,id]=pq.top();
            pq.pop();
            int t=tweetmap[userid][id].second;
            ans.push_back(t);
            if(id>0){
                id--;
                pq.push({tweetmap[userid][id].first,userid,id});
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};
