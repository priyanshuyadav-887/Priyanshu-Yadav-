class MyHashMap {
public:
    vector<list<pair<int,int>>> table;
    int size;

    MyHashMap() {
        size = 1000;
        table.resize(size);
    }

    int hash(int key) {
        return key % size;
    }

    void put(int key, int value) {
        int idx = hash(key);
        for (auto &p : table[idx]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        table[idx].push_back({key, value});
    }

    int get(int key) {
        int idx = hash(key);
        for (auto &p : table[idx]) {
            if (p.first == key) return p.second;
        }
        return -1;
    }

    void remove(int key) {
        int idx = hash(key);
        for (auto it = table[idx].begin(); it != table[idx].end(); it++) {
            if (it->first == key) {
                table[idx].erase(it);
                return;
            }
        }
    }
};