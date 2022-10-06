class Solution {
public:
    
    vector<string> rec(int n){
        
        if(n==1){
            return {"0","1","8"};
        }
        else if(n==2){
            return {"11","69","88","96"};
        }
          vector<string> ans;
        
        if(n%2==0){
          
            vector<string> z=rec(n-2);
            int xi=(n-2)/2;
            for(auto it:z){
                string x=it;
                string y=x.substr(0,xi)+"00"+x.substr(xi);
                string z=x.substr(0,xi)+"11"+x.substr(xi);
                string w=x.substr(0,xi)+"69"+x.substr(xi);
                string t=x.substr(0,xi)+"96"+x.substr(xi);
                string o=x.substr(0,xi)+"88"+x.substr(xi);
                ans.push_back(y);
                ans.push_back(z);
                ans.push_back(w);
                ans.push_back(t);
                ans.push_back(o);
            }
            
            
        }
        else{
            
            vector<string> z=rec(n-1);
            for(auto it:z){
                string x=it;
                string y=x.substr(0,n/2)+"0"+x.substr(n/2);
                string z=x.substr(0,n/2)+"1"+x.substr(n/2);
                string w=x.substr(0,n/2)+"8"+x.substr(n/2);
               
                ans.push_back(y);
                ans.push_back(z);
                ans.push_back(w);
                
            }
            
            
        }
        return ans;
    }
    
    
    vector<string> findStrobogrammatic(int n) {
      return rec(n);
    }
};