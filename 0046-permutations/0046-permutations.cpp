class Solution {
public:
    
    void permutation(vector<vector<int>>&ans ,vector<int>&temp ,vector<bool>&visited ,vector<int>&nums)
    {
        if(temp.size()==nums.size())
        {
            ans.push_back(temp) ;
            return ;
        }
        for(int i=0 ;i<nums.size() ;i++)
        {
            if(!visited[i]){
                visited[i]=1 ;
                temp.push_back(nums[i]) ;
                permutation(ans,temp ,visited ,nums) ;
                visited[i]=0 ;
                temp.pop_back() ;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size() ;
        vector<vector<int>>ans ;
        vector<int>temp ;
        vector<bool>visited(n,0) ;
        permutation(ans,temp,visited,nums) ;
        return ans ;
    }
};