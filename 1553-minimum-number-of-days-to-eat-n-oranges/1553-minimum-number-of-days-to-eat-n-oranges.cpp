class Solution {
public:
    unordered_map<long long int,int> ht;
    int minDays(int n) {
        if(n==0)
            return 0;
        else if(n==1)
            return 1;
        if(ht.find(n)!=ht.end())
            return ht[n];
        
        
        return ht[n]=1+min(n%2+minDays(n/2),n%3+minDays(n/3));
        
    }
};