class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
       
       vector<long long >ans ;
       for(int x:nums)
       {
        if(ans.empty() || ans.back() != x)
        ans.push_back(x) ;

        else
        {
            ans.back() +=x ;

            while(ans.size()>=2 && ans[ans.size()-1]==ans[ans.size()-2])
            {
                long long value=ans.back() ;
                ans.pop_back() ;
                ans.back() +=value ;
            }
        }
       }
       return ans ;
    }
};