class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        int l=1;
        int h=10000000;bool v=false;
        while(l<=h){
           
            int m=(l+h)/2;
            double t=0;
            for(int i=0;i<n;i++){
                t=ceil(t);
                t=t+((double)dist[i]/m);
                
            }
          
            if(t<=hour){
                v=true;
                h=m-1;
            }
            else
                l=m+1;
            
            
            
        }
        if(v)
            return l;
        return -1;
        
    }
};