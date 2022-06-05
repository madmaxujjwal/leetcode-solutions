class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int n=boxes.size();
        int m=warehouse.size();
        sort(boxes.begin(),boxes.end());int c=0;
        
        int pos=0;int mini=warehouse[0];
        for(int i=0;i<m;i++){
            if(mini>warehouse[i]){
                mini=warehouse[i];
                pos=i;
            }
        } mini=INT_MAX;
        for(int i=0;i<pos;i++){
            mini=min(mini,warehouse[i]);
            warehouse[i]=mini;
        }mini=INT_MAX;
        for(int i=m-1;i>pos;i--){
            mini=min(mini,warehouse[i]);
            warehouse[i]=mini;
        }
        
        int i=pos;
        int j=pos;
        int k=0;
        while((k<n)&&(i>=0||j<m)){
            if(i==j){
                if(warehouse[i]>=boxes[k]){
                    c++;k++;
                }
                i--;
                j++;
            }
            else if(i<0&&j<m){
                if(warehouse[j]>=boxes[k]){
                    c++;k++;
                }
                j++;
            }
            else if(i>=0&&j>=m){
                 if(warehouse[i]>=boxes[k]){
                    c++;k++;
                }
                i--;
            }
            else{
                if(warehouse[i]<=warehouse[j]){
                    if(warehouse[i]>=boxes[k]){
                        i--;
                        k++;
                        c++;
                    }
                    
                    else{
                        i--;
                        
                    }
                }
                else{
                    if(warehouse[j]>=boxes[k]){
                        j++;
                        k++;
                        c++;
                    }
                    
                    else{
                        
                        j++;
                    }
                }
            }
        }
        
        
        
        
        
        
        
        
        return c;
    }
};