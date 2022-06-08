class Solution {
public:
    bool isRobotBounded(string instructions) {
        int n=instructions.size();
        int d=0;
        int x=0;
        int y=0;
        for(int j=0;j<4*n;j++){
            int i=j%n;
            if(instructions[i]=='G'){
                if(d==0){
                    y++;
                }
                else if(d==1){
                    x++;
                }
                else if(d==2){
                    y--;
                }
                else{
                    x--;
                }
            }
            else{
                if(instructions[i]=='L'){
                    d--;
                }
                else{
                    d++;
                }
            }
            if(d==3){
                d=-1;
            }
            else if(d==-2){
                d=2;
            }
        }
        if(x==0&&y==0){
            return true;
        }
        return false;
    }
};