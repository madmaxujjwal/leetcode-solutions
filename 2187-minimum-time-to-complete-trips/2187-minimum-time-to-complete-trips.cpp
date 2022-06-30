class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
         long long int n=time.size();
        sort(time.begin(),time.end());
         long long int l=0; long long int h=1e14;
        while(l<h){
             long long int m=l+(h-l)/2;
            
            if(fun(time,totalTrips,m)){
                h=m;
            }
            else
                l=m+1;
        }
        
        return l;
    }
    bool fun(vector<int>& time, int totalTrips, long long int t){
        long long int res=0;
         long long int n=time.size();
        for(int i=0;i<n;i++){
            res+=t/time[i];
        }
        return res>=totalTrips;
    }
};