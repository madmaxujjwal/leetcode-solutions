class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxh;
        int n=piles.size();
        for(int i=0;i<n;i++){
            maxh.push(piles[i]);
        }
        while(k--){
            double z=maxh.top();
            int k=ceil(z/2);
            maxh.pop();
            maxh.push(k);
        }
        int sum=0;
        while(maxh.size()>0){
            sum+=maxh.top();
            maxh.pop();
        }
        return sum;
    }
};