class Solution {
public:
    bool rec(int n){
        if(n==1)
        return true;
        return (n%3==0)&&rec(n/3);
        
        
    }
    bool isPowerOfThree(int n) {
        if(n<=0)return false;
        return rec(n);
    }
};