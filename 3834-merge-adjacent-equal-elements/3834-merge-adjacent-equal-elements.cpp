class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
       vector<long long> res;

        for (int x : nums) {
            
            if (res.empty() || res.back() != x) {
                res.push_back(x);
            } else {
                
                res.back() += x;

                
                while (res.size() >= 2 &&
                       res[res.size() - 1] == res[res.size() - 2]) {
                    long long val = res.back();
                    res.pop_back();
                    res.back() += val;
                }
            }
        }
        return res; 
       
    }
};