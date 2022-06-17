class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> z;
        if((num-3)%3==0){
            long long x=(num-3)/3;
            z.push_back(x);
             z.push_back(x+1);
             z.push_back(x+2);
        }
        return z;
    }
};