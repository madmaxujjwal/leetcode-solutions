class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n=edges.size();
        unordered_map<long long int,long long int> ht;
        for(int i=0;i<n;i++){
            ht[edges[i]]+=i;
        }
        long long int maxi=INT_MIN;long long int ans=-1;
        for(auto it:ht){
           if(maxi<it.second){
               maxi=it.second;
               ans=it.first;
           }
            else if(maxi==it.second&&ans>it.first){
                maxi=it.second;
               ans=it.first;
            }
        }
        return ans;
    }
};