class Solution {
public:
    int minFlips(string target) {
        int steps=target[0]-'0';
        int n=target.size();
        for(int i=1;i<n;i++){
            if(target[i]=='0'){
                if(steps%2!=0){
                    steps++;
                }
            }
            else{
                 if(steps%2==0){
                    steps++;
                }
            }
        }
        return steps;
        
    }
};