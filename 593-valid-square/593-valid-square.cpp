class Solution {
public:
    int dis(vector<int>& p1, vector<int>& p2){
        return (p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> ans;
        ans.push_back(dis(p1,p2));
        ans.push_back(dis(p2,p3));
        ans.push_back(dis(p3,p4));
        ans.push_back(dis(p4,p1));
        ans.push_back(dis(p1,p3));
        ans.push_back(dis(p4,p2));
        sort(ans.begin(),ans.end());
        if(ans[0]!=0&&(ans[0]==ans[1])&&(ans[1]==ans[2])&&(ans[2]==ans[3])&&(2*ans[0]==ans[4])&&(2*ans[0]==ans[5])){
            return true;
        }
        return false;
    }
};