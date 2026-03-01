class Solution {
public:
    int minCost(int n) {
        int t=n-1 ;
        return t*(t+1)/2 ;
    }
};