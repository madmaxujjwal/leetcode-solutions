class Solution {
public:
    int kthFactor(int n, int k) {
        priority_queue<int> maxh;
        for(int i=1;i*i<=(n);i++){
            if(n%i==0){
                maxh.push(i);
                if(n/i!=i){
                     maxh.push(n/i);
                }
            }
            while(maxh.size()>k){
                maxh.pop();
            }
        }
        if(maxh.size()<k)
            return -1;
        return maxh.top();
    }
};