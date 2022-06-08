class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        vector<int> l(n,0);
        vector<int> r(n,0);
        int p=-1;
        for(int i=0;i<n;i++){
            if(seats[i]==1){
                p=i;
                l[i]=-1;
            }
            else{
                l[i]=p;
            }
        }
        p=-1;
        for(int i=n-1;i>=0;i--){
             if(seats[i]==1){
                p=i;
                r[i]=-1;
            }
            else{
                r[i]=p;
            }
        }
        int d=0;
        for(int i=0;i<n;i++){
            if(seats[i]==0){
                int z;int y;
                if(l[i]!=-1)
                 z=i-l[i];
                else
                 z=   INT_MAX;
                if(r[i]!=-1)
                 y=r[i]-i;
                else
                    y=INT_MAX;
            d=max(d,min(z,y));
            }
        }
        return d;
        
    }
};