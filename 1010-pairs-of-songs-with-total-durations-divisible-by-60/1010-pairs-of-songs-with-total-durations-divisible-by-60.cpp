class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) { // basic idea is that one thos two numbers will be divisble by 60 that have their remainders complimentary
        int n=time.size();           // like 105 and 15 their remainders are 45 and 15 so they are divisible so remainders should be x and (60-x)
        unordered_map< long long int, long long int> ht;    // but there is a exception in case of 0 remainders should be 0 and 0                     
        for(int i=0;i<n;i++){         // we have to handle case of 30 also seperatly because in this case both x and 60-x are same so we have to take every two pairs o
            ht[time[i]%60]++;         // remainders of 60 which will be x(x-1)/2  if x=ht[30]       after->                 calculating frequencies of remainders 
        }
        long long int counter=(ht[0]-1)*ht[0]/2+(ht[30]-1)*ht[30]/2;
        for(int i=1;i<30;i++){
            counter+=(ht[i]*ht[60-i]);  // note here we have to take product
        }
        return counter;
        
        
    }
};

/*Amazon
|
11

Citadel
|
8

Bloomberg
|
3

C3 IoT
|
3

Cisco
|
2

Google
|
2

VMware
|
2

Oracle
|
2

Apple
|
2

Infosys
|
2
*/