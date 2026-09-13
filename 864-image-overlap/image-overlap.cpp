class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
         int n = img1.size();
        unordered_map<int, int> mp;

        vector<pair<int,int>> A, B;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) A.push_back({i, j});
                if (img2[i][j] == 1) B.push_back({i, j});
            }
        }

        int res = 0;

        for (auto &a : A) {
            for (auto &b : B) {
                int dx = a.first - b.first;
                int dy = a.second - b.second;

                int key = dx * 100 + dy;
                mp[key]++;
                res = max(res, mp[key]);
            }
        }
        return res;
    }
};