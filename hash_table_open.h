#ifndef HASH_TABLE_HASH_TABLE_OPEN_H
#define HASH_TABLE_HASH_TABLE_OPEN_H

#include <vector>

template<class K, class V>
class hash_table_open {
    std::vector<std::pair<K, V>> data;
    size_t sz;

public:
    hash_table_open(size_t sz) : sz(sz){
        data.resize(sz);
    }

    size_t get_hash(const K& key) const {
        std::hash<K> h;
        auto res = h(key);
        return res % sz;
    }

    size_t get_index(const K& key) const {
        auto bucket = get_hash(key);

        while (data[bucket].first != K{} && data[bucket].first != key) {
            if (++bucket == sz) {
                bucket = 0;
            }
        }

        return bucket;
    }

    void insert(const K& key, const V& val) {
        auto i = get_index(key);

        data[i] = std::make_pair(key, val);
    }

    V get(const K& key) const {
        auto i = get_index(key);

        if (data[i] == nullptr) {
            return V{};
        }

        return data[i].second;
    }

    bool exists(const K& key) const {
        auto i = get_index(key);

        return data[i].first != K{};
    }
};


#endif //HASH_TABLE_HASH_TABLE_OPEN_H
