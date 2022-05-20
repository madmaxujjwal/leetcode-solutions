class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> ht;
        int n=tasks.size();
        for(int i=0;i<n;i++){
            ht[tasks[i]]++;
        }
        int c=0;
        for(auto it:ht){
            if(it.second==1)
                return -1;
            if(it.second%3==0){
                c=c+it.second/3;
            }
            else{
                c=c+it.second/3+1;
            }
        }
        return c;
    }
};