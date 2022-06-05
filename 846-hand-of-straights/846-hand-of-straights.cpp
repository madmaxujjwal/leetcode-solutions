class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int k=groupSize;
        int n=hand.size();
        map<int,int> ht;
        for(int i=0;i<n;i++){
            ht[hand[i]]++;
        }
        for(auto it:ht){
            int z=it.first;
            int x=it.second;
            for(int i=1;i<k;i++){
                int y=z+i;
                if(ht[y]<x){
                    return false;
                }
                ht[y]-=x;
                if(ht[y]==0){
                    ht.erase(y);
                }
            }
        }
        return true;
        
    }
};