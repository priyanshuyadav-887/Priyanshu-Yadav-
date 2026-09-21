
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        
        vector<int> dirs = {0,1,0,-1,0};
        
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int time = cur[0], x = cur[1], y = cur[2];
            
            if (x == n-1 && y == n-1) return time;
            
            if (vis[x][y]) continue;
            vis[x][y] = 1;
            
            for (int d = 0; d < 4; d++) {
                int nx = x + dirs[d];
                int ny = y + dirs[d+1];
                
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny]) {
                    pq.push({max(time, grid[nx][ny]), nx, ny});
                }
            }
        }
        
        return -1;
    }
};
