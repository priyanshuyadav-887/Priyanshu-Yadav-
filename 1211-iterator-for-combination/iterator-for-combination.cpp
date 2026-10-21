class CombinationIterator {
    vector<string> combinations;
    int idx = 0;

    void generate(string &s, int start, int length, string curr) {
        if (curr.size() == length) {
            combinations.push_back(curr);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            generate(s, i + 1, length, curr + s[i]);
        }
    }

public:
    CombinationIterator(string characters, int combinationLength) {
        generate(characters, 0, combinationLength, "");
    }

    string next() {
        return combinations[idx++];
    }

    bool hasNext() {
        return idx < combinations.size();
    }
};