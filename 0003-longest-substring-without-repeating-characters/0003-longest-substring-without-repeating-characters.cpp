class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<bool>count(256,0) ;
        int start=0 ;
        int end=0 ;
        int len=0 ;
        while(end<s.size())
        {
            while(count[s[end]]){
                count[s[start]]=0 ;

                start++ ;
            }
            count[s[end]]=1;
            len=max(len,end-start+1) ;
            end++ ;
        }
        return len ;
    }
};