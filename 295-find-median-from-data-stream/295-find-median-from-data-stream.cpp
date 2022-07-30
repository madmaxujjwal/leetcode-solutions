class MedianFinder {
public:
    priority_queue<double> maxh;
    priority_queue<double,vector<double>,greater<double>> minh;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int a=maxh.size();
        int b=minh.size();
        if(a==b){
            if(a==0&&b==0){
                maxh.push(num);
            }
            else{
                int ele=maxh.top();
                if(num<=ele){
                     maxh.push(num);
                }
                else{
                    minh.push(num);
                }
            }
        }
        else{
            if(a>b){
                int ele=maxh.top();
                if(ele>=num){
                    minh.push(maxh.top());
                    maxh.pop();
                    maxh.push(num);
                }
                else{
                    minh.push(num);
                }
            }
            else{
                int ele=minh.top();
                if(ele>=num){
                   // minh.push(maxh.top());
                   // maxh.pop();
                    maxh.push(num);
                }
                else{
                     maxh.push(minh.top());
                    minh.pop();
                    minh.push(num);
                }
            }
        }
    }
    
    double findMedian() {
        if(minh.size()==maxh.size()){
            
            return (maxh.top()+minh.top())/2;
        }
        else if(minh.size()>maxh.size()){
            return minh.top();
        }
        else
            return maxh.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */