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

const int MAXN = 1e5+1;
vector<int> adj[MAXN];

bool seen[MAXN];
int distances[MAXN];
int parents[MAXN];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    seen[start] = true;

    while (!q.empty()) {
        int a = q.front(); q.pop();
        
        for (int b : adj[a]) {
            if (!seen[b]) {
                seen[b] = true;
                q.push(b);
            }
        }
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
        adj[b].push_back(a);
    }
    
    vector<pair<int,int>> newroads;
    FOR(i, 1, n+1) {
        if (!seen[i]) {
            bfs(i);            
            if (i != 1) newroads.pb({1, i});
        }    
    }

    cout << sz(newroads) << endl;
    REP(i, sz(newroads)) {
        cout << newroads[i].first << " " << newroads[i].second << endl;
    }
}
