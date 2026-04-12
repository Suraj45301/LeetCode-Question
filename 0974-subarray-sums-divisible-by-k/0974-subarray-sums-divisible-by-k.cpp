class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp ;
        int total= 0 ;
        int prefixsum=0 ;
        mp[0]=1 ;

        for(int i=0 ;i<nums.size() ;i++)
        {
             prefixsum +=nums[i] ;
             int rem=prefixsum%k ;

             if(rem<0)
             rem =k+rem ;

             if(mp.count(rem))
             {
                total +=mp[rem] ;
             }
             mp[rem]++ ;
        }
        return total ;
    }
};