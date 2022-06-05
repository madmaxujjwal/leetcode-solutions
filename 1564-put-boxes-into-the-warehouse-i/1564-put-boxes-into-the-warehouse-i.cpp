class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int n=boxes.size();
        int m=warehouse.size();int mini=INT_MAX;
        for(int i=0;i<m;i++){
           mini=min(mini,warehouse[i]);
             warehouse[i]=mini;
        }
        sort(boxes.begin(),boxes.end());
        int i=0;
        int j=m-1;int c=0;
        while(i<n&&j>=0){
            if(boxes[i]<=warehouse[j]){
                i++;
                j--;c++;
            }
            else{
                j--;
            }
        }
        return c;
    }
};