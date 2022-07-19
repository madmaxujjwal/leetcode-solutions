class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m=quantities.size();
        int l=1;
        int h=100000;
        while(l<=h){
            int x=(l+h)/2;
            int sum=0;
            for(int i=0;i<m;i++){
                sum=sum+ceil((double)quantities[i]/x);
            }
            //return sum;
            if(sum<=n){
                h=x-1;
            }
            else
                l=x+1;
            
            
        }
        return l;
    }
};