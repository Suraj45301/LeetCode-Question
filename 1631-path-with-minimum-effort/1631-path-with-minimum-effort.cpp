class Solution {
public:
   int r,c ;
   int row[4] = {-1, 0, 1, 0};
   int col[4] = {0, 1, 0, -1};
   bool valid(int i,int j)
   {
    return i>=0 && i<r && j>=0 && j<c ;
   }
    int minimumEffortPath(vector<vector<int>>& heights) {
         r=heights.size() ;
         c=heights[0].size() ;

        vector<vector<int>> dist(r, vector<int>(c, INT_MAX));

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<>
        > pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto [effort, cell] = pq.top();
            pq.pop();
            int i = cell.first;
            int j = cell.second;

            if (i == r-1 && j == c-1)
                return effort;

            for (int k = 0; k < 4; k++) {
                int ni = i + row[k];
                int nj = j + col[k];

                if (valid(ni, nj)) {
                    int newEffort = max(
                        effort,
                        abs(heights[i][j] - heights[ni][nj])
                    );

                    if (newEffort < dist[ni][nj]) {
                        dist[ni][nj] = newEffort;
                        pq.push({newEffort, {ni, nj}});
                    }
                }
            }
        }
        return 0;
    }
};