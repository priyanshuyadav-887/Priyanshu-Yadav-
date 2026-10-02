class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        if (!st.count(endGene)) return -1;

        queue<string> q;
        q.push(startGene);

        unordered_set<string> vis;
        vis.insert(startGene);

        vector<char> genes = {'A','C','G','T'};
        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string curr = q.front(); q.pop();
                if (curr == endGene) return steps;

                for (int i = 0; i < curr.size(); i++) {
                    char old = curr[i];
                    for (char g : genes) {
                        curr[i] = g;
                        if (st.count(curr) && !vis.count(curr)) {
                            vis.insert(curr);
                            q.push(curr);
                        }
                    }
                    curr[i] = old;
                }
            }
            steps++;
        }

        return -1;
    }
};