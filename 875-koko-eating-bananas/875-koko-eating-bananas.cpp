class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int zi) {
         unsigned long long int n=piles.size();long long int h=zi;
        if(n==1){
            return ceil((double)(piles[0])/h);
        }
        unsigned long long int sum=0; unsigned long long int maxi=piles[0];
        for(int i=0;i<n;i++){
            sum+=piles[i];
            maxi=max(maxi,(unsigned long long int)piles[i]);
        }
         unsigned long long int a=ceil(sum/h);
         unsigned long long int b=maxi;
        while(a<=b){
             unsigned long long int m=(a+b)/2;
             unsigned long long int z=0;int y=0;
             for( unsigned long long int i=0;i<n;i++){
            z=z+((piles[i])/m+((piles[i]%m)!=0));
                 
        }
            for(int i=0;i<n;i++){
            y=y+((piles[i])/(m-1)+((piles[i]%(m-1))!=0));
                 
        }
            if(z==h&&y!=h){
                return m;
            }
            else if((z==h&&y==h)||(z<h)){
                b=m-1;
            }
            else{
                a=m+1;
            }
        }
        
        return a;
    }
};