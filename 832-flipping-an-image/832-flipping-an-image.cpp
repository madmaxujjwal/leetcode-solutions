class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n=image.size();
        for(int j=0;j<n;j++){
        for(int i=0;i<(n/2+n%2);i++){
            int a=image[j][i];
           
            int b=image[j][n-1-i];
            // return{ {b^a}};
            if((a^b)==0){
                image[j][i]=1^a;
                image[j][n-1-i]=1^b;
            }
            
        }
        }
        return image;
        
    }
};