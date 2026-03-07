class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       unordered_set<string>st(wordList.begin() ,wordList.end());
       if(st.find(endWord) == st.end()) return 0;
       queue<pair<string,int>>q ;
       q.push({beginWord,1});
     

       while(!q.empty())
       {
          string word=q.front().first ;
          int step=q.front().second ;
          q.pop() ;

          if(word==endWord)
          return step ;

          for(int j=0 ;j<word.size();j++)
          {
            char original=word[j] ;
            for(char ch='a' ;ch<='z';ch++)
            {
                word[j]=ch ;
                if(st.find(word) != st.end())
                {
                    q.push({word,step+1});
                    st.erase(word);
                }
            }
            word[j]=original ;
          }
       } 
       return 0;
    }
    
};