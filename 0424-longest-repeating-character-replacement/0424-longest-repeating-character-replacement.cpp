class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>mp(256,0) ;
        int start=0,end=0,len=0 ;
        int maxfreq=0 ;

        for(int i=0 ;i<s.size() ;i++)
        {
           mp[s[end]]++ ;
           maxfreq=max(maxfreq,mp[s[end]]) ;
           while((end-start+1)-maxfreq >k)
           {
            mp[s[start]]-- ;
            start++ ;
           }
           len=max(len,end-start+1) ;
           end++ ;
        }
        return len ;
    }
};