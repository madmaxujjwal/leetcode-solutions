class Solution {
public:
    bool rec(int n){
        
        
        if(n==1)return true;
        return (n%4==0)&&rec(n/4);
    }
    bool isPowerOfFour(int n) {
        
        if(n<=0)return false;
        return rec(n);
    }
};