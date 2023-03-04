#include "template.h"

class UnionFind {
    public:
    vector<ll> parent, ranks;

    UnionFind(ll num_nodes) : parent(num_nodes, 0), ranks(num_nodes, 0) {}

    void make_set(ll v) {
        parent[v] = v;
        ranks[v] = 0;
    }

    int find_set(ll v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(ll a, ll b) {
        a = find_set(a);
        b = find_set(b);
        
        if (a != b) {
            if (ranks[a] < ranks[b])
                swap(a, b);
            parent[b] = a;
            if (ranks[a] == ranks[b])
                ranks[a]++;
        }
    }

};
