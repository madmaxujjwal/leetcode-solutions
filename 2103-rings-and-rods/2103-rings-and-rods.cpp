class Solution {
public:
    int countPoints(string rings) {
        int n=rings.size();
        int count[10][3];
        memset(count,0,sizeof(count));
        for(int i=0;i<n;i=i+2){
            char a=rings[i];
            int b=(int)(rings[i+1]-'0');
           // return b;
            if(a=='R'){
                count[b][0]=1;
            }
            else if(a=='G'){
                count[b][1]=1;
            }
            else{
                count[b][2]=1;
            }
        }
        
        int c=0;
        for(int i=0;i<10;i++){
            if((count[i][0]+count[i][1]+count[i][2])==3)
                c++;
        }
        return c;
    }
};