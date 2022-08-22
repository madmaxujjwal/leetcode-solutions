class Solution {
public:
    vector<int> arr;int n;int len;
    vector<int> temp;int an;
    int fact(int x){
        if(x==1||x==0)
            return 1;
        return x*fact(x-1);
    }
    void rec(int i){
        if(i==len){
            int ans=0;
            int p=1;
            for(int j=0;j<temp.size();j++){
                p=p*fact(temp[j]);
                ans=ans+temp[j];
            }
            an += fact(ans)/p;
            return ;
        }
        for(int j=0;j<=arr[i];j++){
            temp.push_back(j);
            rec(i+1);
            temp.pop_back();
        }
        
    }
    int numTilePossibilities(string tiles) {
         n=tiles.size();
        unordered_map<char,int> ht;an=0;
        for(int i=0;i<n;i++){
            ht[tiles[i]]++;
        }
        for(auto it:ht){
            arr.push_back(it.second);
        }
        
        n=arr.size();
        len=arr.size();
         rec(0);
        return an-1;
    }
};