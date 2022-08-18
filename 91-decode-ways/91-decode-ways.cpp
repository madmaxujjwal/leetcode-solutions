class Solution {
public:
    unordered_map<string,char> ht;
    int n;
    string str;
    int dp[101];
    int rec(int x){
        if(x==0){
            return 1;
        }
        if(x<0)
            return 0;
        if(dp[x]!=-1)
            return dp[x];
        string z;
        if(x>=2)
        z=str.substr(x-2,2);
        int ans=0;
        if(ht.find(z)!=ht.end()){
            ans+=rec(x-2);
        }
        if(ht.find(str.substr(x-1,1))!=ht.end()){
            ans+=rec(x-1);
        }
        return dp[x]= ans;
    }
    int numDecodings(string s) {
        str=s;
        memset(dp,-1,sizeof(dp));
        ht["1"]='A';
        ht["2"]='B';
        ht["3"]='C';
        ht["4"]='D';
        ht["5"]='E';
        ht["6"]='F';
        ht["7"]='G';
        ht["8"]='H';
        ht["9"]='I';
        ht["10"]='J';
        ht["11"]='K';
        ht["12"]='L';
        ht["13"]='M';
        ht["14"]='N';
        ht["15"]='O';
        ht["16"]='P';
        ht["17"]='Q';
        ht["18"]='R';
        ht["19"]='S';
        ht["20"]='T';
        ht["21"]='U';
        ht["22"]='V';
        ht["23"]='W';
        ht["24"]='X';
        ht["25"]='Y';
        ht["26"]='Z';
        n=s.size();
       
        
        return rec(n);
        
    }
};