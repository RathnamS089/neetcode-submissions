class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> pref(arr.size());
        for(int i=0;i<arr.size();i++){
             int m=INT_MIN;
             for(int j=i+1;j<arr.size();j++){
                m=max(m,arr[j]);
             }
             pref[i]=m;
        }
        pref[arr.size()-1]=-1;
        return pref;
    }
};