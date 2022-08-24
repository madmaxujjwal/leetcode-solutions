class Solution {
public:
     long double rec(long long int z,long double x){
         
        if(z==0){
            return 1;
        }
         long double half=rec(z/2,x);
        if(z==1){
            return x;
        }
        else if(z%2==0){
            return half*half;
        }
        else
            return x*half*half;
    }
    double myPow(double x, int n) {
       // return INT_MAX;
        long long int z=n;
        
         long double ans=rec(abs(z),x);
        if(n>=0)
            return ans;
        else
            return 1/ans;
        
    }
};