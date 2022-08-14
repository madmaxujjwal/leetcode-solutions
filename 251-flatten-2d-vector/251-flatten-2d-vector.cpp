class Vector2D {
public:
    vector<int> z;int n;int i;
    Vector2D(vector<vector<int>>& vec) {
       
        i=0;
        for(int j=0;j<vec.size();j++){
            for(auto it:vec[j]){
                z.push_back(it);
            }
        }
        n=z.size();
    }
    
    int next() {
        return z[i++];
    }
    
    bool hasNext() {
        return i<n;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */