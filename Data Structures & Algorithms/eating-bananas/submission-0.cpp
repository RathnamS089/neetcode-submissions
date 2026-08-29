class Solution {
public:
    bool canfinish(vector<int>&piles,int x,int h){
          int hours=0;
          for(int pile:piles){
             hours+=(pile+x-1)/x;
          }
          return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        while(l<=r){
            int mid=l+(r-l)/2;
            if(canfinish(piles,mid,h)){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};
