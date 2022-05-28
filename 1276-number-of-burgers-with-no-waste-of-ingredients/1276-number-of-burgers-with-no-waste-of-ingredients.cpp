class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int t=tomatoSlices;
        int c=cheeseSlices;
        if(t==0&&c==0)
            return{0,0};
        int x=(t-2*c)/2;
        int y=(4*c-t)/2;
        if((t-2*c)%2==0&&(4*c-t)%2==0&&x>=0&&y>=0){
            return {x,y};
        }
        return {};
    }
};