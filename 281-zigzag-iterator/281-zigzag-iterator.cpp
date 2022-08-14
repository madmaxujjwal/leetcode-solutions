class ZigzagIterator {
public:
    vector<int> z;int p;int s;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int n=v1.size();int m=v2.size();
        int i=0;int j=0;
        while(i<n||j<m){
            if(i<n){
                z.push_back(v1[i]);
                i++;
            }
            if(j<m){
                z.push_back(v2[j]);
                j++;
            }
        }
        p=0;s=z.size();
    }

    int next() {
        return z[p++];
    }

    bool hasNext() {
        return p<s;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */