class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        int i=0;int p=-1;string s=dominoes;string ans=s;
        while(p<n&&i<n){
            if(s[i]!='.'){
                if(s[i]=='L'){
                    for(int k=p+1;k<i;k++){
                        ans[k]='L';
                    }
                    p=i;
                    i++;
                }else{
                    for(int k=i+1;k<=n;k++){
                        if(k==n||s[k]=='R'){
                            for(int z=i+1;z<k;z++){
                                ans[z]='R';
                            }
                            p=k;
                            i=k;break;
                        }else if(s[k]=='L'){
                            int a=i+1;int b=k-1;
                            while(a<=b){
                                if(a==b){
                                    ans[a]='.';break;
                                }
                                ans[a++]='R';
                                ans[b--]='L';
                            }
                            p=k;
                            i=k+1;break;
                        }
                    }
                    
                    
                    
                    
                }
            }
            else{
                i++;
            }
            
        }
        return ans;
    }
};