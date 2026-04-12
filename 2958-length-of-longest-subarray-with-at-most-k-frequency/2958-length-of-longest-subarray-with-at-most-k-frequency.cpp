class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp ;

        int start=0 ;
        int end=0 ;
        int maxi=INT_MIN ;
        while(end<nums.size())
        {
           mp[nums[end]]++ ;
           while(mp[nums[end]]>k)
           {
            mp[nums[start]]-- ;
            start++ ;
           }
           maxi=max(maxi,end-start+1) ;

           end++ ;
        }
        return maxi ;
    }
};