class Solution {
public:
    
    void subseq(vector<int>&nums ,vector<vector<int>>&ans ,int index ,int size,vector<int>&temp)
    {
        if(index==size)
        {
            ans.push_back(temp) ;
            return ;
        }
        subseq(nums,ans,index+1 ,size,temp) ;
        temp.push_back(nums[index]) ;
        subseq(nums,ans,index+1,size,temp) ;
        temp.pop_back() ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n=nums.size() ;
        vector<vector<int>>ans ;
        vector<int>temp ;
        subseq(nums ,ans ,0 ,n,temp) ;
        return ans ;
    }
};