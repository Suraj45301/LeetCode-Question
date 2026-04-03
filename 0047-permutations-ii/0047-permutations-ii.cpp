class Solution {
public:

   void permute(vector<vector<int>>&ans ,vector<int>&nums ,int index)
   {
    if(nums.size()==index)
    {
        ans.push_back(nums);
        return ;
    }
    unordered_set<int> used;
    for(int i=index ;i<nums.size() ;i++)
    {
      if(used.count(nums[i])) continue; 

      used.insert(nums[i]);
        swap(nums[index],nums[i]) ;
        permute(ans,nums,index+1) ;
        swap(nums[i],nums[index]) ;
    }
   }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans ;
        //sort(nums.begin() ,nums.end()) ;
        permute(ans,nums,0) ;
        return ans ;
    }
};