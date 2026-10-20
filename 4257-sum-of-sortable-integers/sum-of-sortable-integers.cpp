class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k * k <= n; k++) {
            if (n % k != 0) continue;

            if (check(nums, k)) ans += k;

            int other = n / k;
            if (other != k && check(nums, other))
                ans += other;
        }

        return ans;
    }

    bool check(vector<int>& nums, int k) {
        int n = nums.size();
        int prevMax = 0;

        for (int start = 0; start < n; start += k) {
            int mn = nums[start];
            int mx = nums[start];
            int drops = 0;

            for (int j = start; j < start + k; j++) {
                int next = (j + 1 == start + k) ? start : j + 1;

                if (nums[j] > nums[next])
                    drops++;

                if (drops > 1)
                    return false;

                mn = min(mn, nums[j]);
                mx = max(mx, nums[j]);
            }

            if (start > 0 && prevMax > mn)
                return false;

            prevMax = mx;
        }

        return true;
    }
};