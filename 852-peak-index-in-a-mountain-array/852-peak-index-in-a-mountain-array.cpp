class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int i=0;
        int j=arr.size()-1;int m;
        while(i<j){
            m=(i+j)/2;
            if(m>0&&m<n-1&&(arr[m-1]<arr[m])&&(arr[m]>arr[m+1])){
                return m;
            }
            else if(m>0&&m<n-1&&(arr[m-1]<arr[m])&&(arr[m]<arr[m+1])){
                i=m+1;
            }
            else if(m>0&&m<n-1&&(arr[m-1]>arr[m])&&(arr[m]>arr[m+1])){
                j=m-1;
            }
            else if(m==0){
                i++;
            }
           else{
               j--;
           }
        }
        return i;
    }
};