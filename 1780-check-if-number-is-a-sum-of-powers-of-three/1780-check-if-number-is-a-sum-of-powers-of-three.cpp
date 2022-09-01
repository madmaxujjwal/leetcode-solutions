class Solution {
public:
    bool checkPowersOfThree(int n) {
        
        if(n==1||n==0)
            return true;
        if(n==2)
            return false;
        return checkPowersOfThree(n%3)&&checkPowersOfThree(n/3);
    }
};