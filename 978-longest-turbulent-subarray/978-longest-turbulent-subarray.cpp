class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        if(n==1)
            return n;
        if(n==2){
            if(arr[0]==arr[1])
                return 1;
            return 2;
        }
        int ans=2;int c=2;bool v=false;
        if(arr[0]!=arr[1])
            v=true;
        for(int i=1;i<n-1;i++){
            if(arr[i]!=arr[i+1])
                v=true;
            if(((arr[i+1]-arr[i])>0&&(arr[i]-arr[i-1])<0)||((arr[i+1]-arr[i])<0&&(arr[i]-arr[i-1])>0)){
                c++;
            }
            else{
                c=2;
            }
            ans=max(ans,c);
        }
        if(!v)
            return 1;
        return ans;
    }
};