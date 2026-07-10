class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0,r=1;
        int profit=0;
        while(r<prices.size()){
           if(prices[l]<prices[r]){
             int a=prices[r]-prices[l];
             profit=max(profit,a);
           }
           else{
             l=r;
           }
           r+=1;
        }
        return profit;
    }
};
