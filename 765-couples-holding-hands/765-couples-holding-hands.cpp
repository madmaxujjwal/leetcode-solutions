class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        unordered_map<int,int> ht;
        for(int i=0;i<n;i++){
            ht[row[i]]=i;
        }
        int c=0;
        for(int i=0;i<n-1;i=i+2){
            int z=row[i];int f;
            if(z%2==0){
                f=z+1;
                if(row[i+1]==f){
                    continue;
                }
                int index=ht[f];
                swap(ht[row[index]],ht[row[i+1]]);
                swap(row[index],row[i+1]);
                
                c++;
            }
            else{
                f=z-1;
                if(row[i+1]==f){
                    continue;
                }
                int index=ht[f];
                 swap(ht[row[index]],ht[row[i+1]]);
                swap(row[index],row[i+1]);
                c++;
            }
        }
        return c;
    }
};