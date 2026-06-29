class Solution {
public:
    int squares(int &n){
        int output=0;
        while(n>0){
            int digit=n%10;
            output+=digit*digit;
            n=n/10;
        }
        return output;
    }
    bool isHappy(int n) {
        set<int> m;
        while(!m.count(n)){
           m.insert(n);
           n=squares(n);
           if(n==1){
             return true;
             break;
           }
        }
        return false;
    }
};
