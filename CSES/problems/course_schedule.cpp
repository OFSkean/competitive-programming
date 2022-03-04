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

const int MAXN=1e5+1;
vector<int> adj[MAXN];
bool seen[MAXN];
bool finished[MAXN];

// remember to reverse sort this when printing it
vector<int> topo;

void dfs(int s) {
    if (finished[s]) {
        return;
    }
    else if (seen[s]) {
        cout << "IMPOSSIBLE" << endl;
        exit(0);
    }


    seen[s] = true;
    for (int i : adj[s]) {
        dfs(i);
    }
    
    seen[s] = false; 
    finished[s] = true;
    topo.push_back(s);
}

void solve(int n) {
    FOR(i, 1, n+1) {
        if (!finished[i]) dfs(i);
    }
}

int main() {
    SPEED;

    int n, m;
    cin >> n >> m;

    REP(i, m) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    solve(n);

    for (auto it = topo.rbegin(); it != topo.rend(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
