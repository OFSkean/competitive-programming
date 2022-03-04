#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)

// put weight first in edge tuple for sorting
vector<int> parent, ranks;
vector<tuple<ll, int, int>> edges;

void make_set(int v) {
    parent[v] = v;
    ranks[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
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

// can be modified to return cost or minimal edge set
ll kruskal(int n) {
    sort(edges.begin(), edges.end());
    
    parent.resize(n+1);
    ranks.resize(n+1);
    
    FOR(i, 1, n+1) {
        make_set(i);
    }
    
    ll cost = 0;
    vector<pair<int,int>> result;

    for (auto e : edges) {
        ll w; int u, v;
        tie(w, u, v) = e;

        if (find_set(u) != find_set(v)) {
            cost += w;
            result.push_back({u, v});
            union_sets(u, v);
        }
    }
    
    // check for impossibility
    if (result.size() < n-1) {
        return -1;
    }

    return cost;
}

int main() {
	SPEED;
    int n, m;
    cin >> n >> m;
    
    set<pair<int,int>> seenPairs;

    REP(i, m) {
        int a, b; ll c;
        cin >> a >> b >> c;
        edges.push_back({c,a,b});
        edges.push_back({c,b,a});
    }

    ll result = kruskal(n);
    if (result == -1) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        cout << result << endl;
    }
}
