class StockPrice {
public:
    int t;
    priority_queue<pair<int,int>> maxh;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minh;
    unordered_map<int,int> ht;
    StockPrice() {
     t=0;   
    }
    
    void update(int timestamp, int price) {
        t=max(t,timestamp);
        ht[timestamp]=price;
        maxh.push({price,timestamp});
        minh.push({price,timestamp});
    }
    
    int current() {
        return ht[t];
    }
    
    int maximum() {
        while(true){
            int m=maxh.top().first;
            int time=maxh.top().second;
            if(ht[time]!=m)
                maxh.pop();
            else
                break;
        }
        return maxh.top().first;
    }
    
    int minimum() {
        while(true){
            int m=minh.top().first;
            int time=minh.top().second;
            if(ht[time]!=m)
                minh.pop();
            else
                break;
        }
        return minh.top().first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */