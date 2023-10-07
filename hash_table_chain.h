#ifndef HASH_TABLE_HASH_TABLE_CHAIN_H
#define HASH_TABLE_HASH_TABLE_CHAIN_H

#include <list>

template<class K, class V>
class hash_table_chain {
    std::vector<std::list<std::pair<K, V>>> data;
    size_t sz;

public:
    hash_table_chain(size_t sz) : sz(sz) {
        data.resize(sz);
    }

    size_t get_hash(const K& key) const{
        std::hash<K> h;
        auto res = h(key);
        return res % sz;
    }

    void insert(const K& key, const V& val) {
        std::list<std::pair<K, V>> chain = data[get_hash(key)];

        if (in_chain(chain, key)) return;

        chain.emplace_back(key, val);
    }

    V get(const K& key) const {
        std::list<std::pair<K, V>> chain = data[get_hash(key)];

        for (auto &pr : chain) {
            if (pr.first == key) {
                return pr.second;
            }
        }

        return V{};
    }

    bool exists(const K& key) const {
        std::list<std::pair<K, V>> chain = data[get_hash(key)];

        return in_chain(chain, key);
    }

    bool in_chain(const std::list<std::pair<K, V>>& chain, const K& key) const {
        for (auto& pr : chain) {
            if (pr.first == key) {
                return true;
            }
        }

        return false;
    }
};

#endif //HASH_TABLE_HASH_TABLE_CHAIN_H
