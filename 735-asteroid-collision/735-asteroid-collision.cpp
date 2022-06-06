class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n=asteroids.size();int i=0;
       
        while(i<n){
            if(st.size()==0){
                st.push(asteroids[i]);
            }
            else{
                if(st.top()*asteroids[i]>0){
                    st.push(asteroids[i]);
                }
                else{
                    if(asteroids[i]<0){
                    while(st.size()!=0&&st.top()>0&&((st.top()+(asteroids[i]))<0)){
                        st.pop();
                    }
                        if(st.size()!=0&&((st.top()+asteroids[i])==0)){
                            st.pop();i++;
                        continue;}
                        if(st.size()==0||st.top()<0){
                            st.push(asteroids[i]);
                        }
                        
                    }
                    else{
                  /*      while((st.top()+(asteroids[i]))>0){
                        st.pop();
                    }
                        if(st.size()!=0&&(st.top()+asteroids[i])==0){
                            st.pop();
                        continue;}
                        if(st.size()==0||st.top()>0){
                            st.push(asteroids[i]);
                        }*/
                        st.push(asteroids[i]);
                    }
                    
                }
            }
            i++;
        }
        vector<int> ans;
        while(st.size()!=0){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};