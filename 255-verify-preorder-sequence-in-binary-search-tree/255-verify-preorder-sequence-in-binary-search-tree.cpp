class Solution {
public:
    vector<int> io;
    vector<int> po;
    int n;
    int p;
    bool build(int i,int j){
        if(i>j){
            return true;
        }
        int s=lower_bound(io.begin()+i,io.begin()+j+1,po[p++])-io.begin();
        if(s==j+1)
            return false;
        return build(i,s-1)&&build(s+1,j);
        
    }
    bool verifyPreorder(vector<int>& preorder) {
        po=preorder; n=po.size();p=0;
        for(int i=0;i<n;i++){
            io.push_back(po[i]);   
         }
        sort(io.begin(),io.end());
        return build(0,n-1);
    }
};