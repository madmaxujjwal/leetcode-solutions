class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> maxh;
        if(a>0)
        maxh.push({a,'a'});
        if(b>0)
        maxh.push({b,'b'});
        if(c>0)
        maxh.push({c,'c'});
        string ans="";
        while(maxh.size()>0){
            if(ans.size()<2){
                char ch=maxh.top().second;
                int z=maxh.top().first;
                ans+=ch;
                maxh.pop();
                if(z>1){
                    maxh.push({z-1,ch});
                }
            }
            else{
                char ch1=maxh.top().second;
                int z1=maxh.top().first;
                if(ans[ans.size()-1]==ch1&&ans[ans.size()-2]==ch1){
                    maxh.pop();
                    if(maxh.size()==0)
                        break;
                    char ch2=maxh.top().second;
                int z2=maxh.top().first;
                    ans+=ch2;
                    maxh.pop();
                    if(z2>1){
                        maxh.push({z2-1,ch2});
                    }
                    maxh.push({z1,ch1});
                }
                else{
                    char ch=maxh.top().second;
                int z=maxh.top().first;
                ans+=ch;
                maxh.pop();
                if(z>1){
                    maxh.push({z-1,ch});
                }
                }
                
                
                
                
                
            }
        }
        return ans;
        
    }
};