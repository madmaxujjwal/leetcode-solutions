class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n=barcodes.size();
        priority_queue<pair<int,int>> maxh;
        unordered_map<int,int> ht;
        for(int i=0;i<n;i++){
            ht[barcodes[i]]++;
        }
        for(auto it:ht){
            maxh.push({it.second,it.first});
        }
        vector<int> ans;
        while(maxh.size()!=0){
            if(ans.size()==0){
                pair<int,int> z=maxh.top();
                maxh.pop();
                int a=z.first;int b=z.second;
                ans.push_back(b);
                a--;
                if(a!=0){
                    maxh.push({a,b});
                }
            }
            else{
                if(ans[ans.size()-1]!=maxh.top().second){
                     pair<int,int> z=maxh.top();
                int a=z.first;int b=z.second;maxh.pop();
                ans.push_back(b);
                a--;
                if(a!=0){
                    maxh.push({a,b});
                }
                }
                else{
                     pair<int,int> y=maxh.top();maxh.pop();
                    pair<int,int> z=maxh.top();maxh.pop();
                int a=z.first;int b=z.second;
                ans.push_back(b);
                a--;
                if(a!=0){
                    maxh.push({a,b});
                }
                    maxh.push(y);
                }
                
            }
        }
        return ans;
    }
};