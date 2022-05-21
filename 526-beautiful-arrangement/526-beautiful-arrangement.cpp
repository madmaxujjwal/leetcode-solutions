class Solution {
public:
    void search(int n,vector<int> &z,int &c, vector<bool> present){
        if(z.size()==n){
            c++;
            return;
        }
        for(int i=1;i<=n;i++){
            if(present[i-1]==true||((i%(z.size()+1)!=0)&&((z.size()+1)%i!=0)))
                continue;
            present[i-1]=true;
            
            z.push_back(i);
               search(n,z,c,present);
            z.pop_back();
               present[i-1]=false;
            
            
        }
    }
    int countArrangement(int n) {
        vector<bool> present(n,false);
        vector<int> z;int c=0;
        search(n,z,c,present);
        return c;
    }
};