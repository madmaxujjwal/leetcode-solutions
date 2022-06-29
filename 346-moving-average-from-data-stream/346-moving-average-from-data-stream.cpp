class MovingAverage {
public:
    int n;
    queue<int> q;
    int sum;
    MovingAverage(int size) {
        n=size;
        sum=0;
        
    }
    
    double next(int val) {
        q.push(val);
        sum+=val;
        if(q.size()>n){
            int t=q.front();
            q.pop();
            sum=sum-t;
        }
       double a=sum;
        return a/q.size();
      
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */