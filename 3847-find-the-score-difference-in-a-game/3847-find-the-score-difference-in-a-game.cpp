class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int score1 =0 ;
        int score2=0 ;
        bool flag=1;
        
        for(int i=0 ;i<nums.size() ;i++)
            {
                if(nums[i]%2 !=0)
                flag=!flag ;

                if(i%6==5)
                flag=!flag ;

                if(flag)
                score1 +=nums[i] ;

                else{
                   score2 +=nums[i] ;
                }
            }
            return score1-score2 ;
    }
};