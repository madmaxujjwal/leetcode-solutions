class LRUCache {
public:
    deque<pair<int,int>> q;int n;int size;
    unordered_map<int,int> ht;
    unordered_map<int,int> id;
    LRUCache(int capacity) {
        n=capacity;
        size=0;
    }
    
    int get(int key) {
        if(ht.find(key)==ht.end()){
            return -1;
        }
        id[key]++;
        q.push_back({key,id[key]});
        return ht[key];
    }
    
    void put(int key, int value) {
        
        if(ht.find(key)!=ht.end()){
            if(ht.find(key)!=ht.end()){
        ht[key]=value;
                id[key]++;
        q.push_back({key,id[key]});
                return ;
            }
            
        }
        if(size<n){
            if(ht.find(key)!=ht.end()){
        ht[key]=value;
                id[key]++;
        q.push_back({key,id[key]});
        
        }
            else{
                ht[key]=value;
                id[key]=0;
                 q.push_back({key,id[key]});
                
            }
            size++;
        }
        else{
            while(q.front().second!=id[q.front().first]){
                q.pop_front();
            }
            id.erase(q.front().first);
            ht.erase(q.front().first);
            q.pop_front();
             if(ht.find(key)!=ht.end()){
        ht[key]=value;
                id[key]++;
        q.push_back({key,id[key]});
        
        }
            else{
                ht[key]=value;
                id[key]=0;
                 q.push_back({key,id[key]});
                
            }
            
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */