class Leaderboard {
public:
    unordered_map<int,int> ht;
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        ht[playerId]+=score;
    }
    
    int top(int K) {
        priority_queue<int,vector<int>,greater<int>> minh;
        for(auto it:ht){
            minh.push(it.second);
            if(minh.size()>K){
                minh.pop();
            }
        }
        int sum=0;
        while(minh.size()!=0){
            sum+=minh.top();
            minh.pop();
        }
        return sum;
    }
    
    void reset(int playerId) {
        ht.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */