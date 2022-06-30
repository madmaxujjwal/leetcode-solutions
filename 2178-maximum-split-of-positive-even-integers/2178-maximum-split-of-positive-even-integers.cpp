class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
       if(finalSum%2!=0)
           return {};
        long long S=0;
    vector<long long> ans;
        for(int i=2;;i=i+2){
            S=S+i;
            if(S>finalSum){
                S=S-i-i+2;
                ans.pop_back();
                long long v=finalSum-S;
                ans.push_back(v);
                break;
            }
            if(S==finalSum){
                ans.push_back(i);
                break;
            }
            ans.push_back(i);
        }
        return ans;
    }
};