class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = s.size(), m = words.size(), len = words[0].size();
        int total = m * len;

        if (n < total) return ans;

        unordered_map<string, int> target;
        for (auto& word : words) target[word]++;

        for (int offset = 0; offset < len; offset++) {
            unordered_map<string, int> window;
            int left = offset, count = 0;

            for (int right = offset; right + len <= n; right += len) {
                string word = s.substr(right, len);

                if (target.count(word)) {
                    window[word]++;
                    count++;

                    while (window[word] > target[word]) {
                        string removed = s.substr(left, len);
                        window[removed]--;
                        left += len;
                        count--;
                    }

                    if (count == m) {
                        ans.push_back(left);
                        string removed = s.substr(left, len);
                        window[removed]--;
                        left += len;
                        count--;
                    }
                } else {
                    window.clear();
                    count = 0;
                    left = right + len;
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};