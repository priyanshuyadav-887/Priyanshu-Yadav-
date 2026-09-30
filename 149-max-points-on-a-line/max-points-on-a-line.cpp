class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
   int n = points.size();
        if (n <= 2) return n;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<long double, int> mp;
            int same = 1;

            for (int j = i + 1; j < n; j++) {
                if (points[i] == points[j]) {
                    same++;
                } else {
                    long double dx = points[j][0] - points[i][0];
                    long double dy = points[j][1] - points[i][1];
                    long double slope = (dx == 0) ? LLONG_MAX : dy / dx;
                    mp[slope]++;
                }
            }

            int curr = 0;
            for (auto &p : mp) {
                curr = max(curr, p.second);
            }

            ans = max(ans, curr + same);
        }

        return ans;     
    }
};