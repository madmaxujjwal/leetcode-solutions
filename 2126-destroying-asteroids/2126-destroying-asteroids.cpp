class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int n=asteroids.size();unsigned long long int t=mass;
              for(int i=0;i<n;i++){
              if(t<asteroids[i]){
                  return false;
              }
                 t=t+asteroids[i];
        }
        return true;
    }
};