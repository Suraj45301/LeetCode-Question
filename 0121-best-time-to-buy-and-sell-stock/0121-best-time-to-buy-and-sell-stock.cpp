class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0 ;
        int start=0 ;
        int end=1 ;
        while(end<prices.size())
        {
            if(prices[start]>prices[end])
            {
                start=end ;
            }
            else{
                profit=max(profit,prices[end]-prices[start]) ;
            }
            end++ ;
        }
        return profit ;
    }
};