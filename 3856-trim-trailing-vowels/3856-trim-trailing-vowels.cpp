class Solution {
public:
    string trimTrailingVowels(string s) {
        string t="" ;
        int n=s.size()-1  ;
        while(n>=0)
        {
            if(s[n] !='a' && s[n] !='e' && s[n] !='i' && s[n] !='o' && s[n] !='u')
            
            {
                break ;
            }
            else{
                n-- ;
            }
        }
        for(int i=0 ;i<=n ;i++)
        {
            t +=s[i] ;
        }
        return t ;
       
    }
};