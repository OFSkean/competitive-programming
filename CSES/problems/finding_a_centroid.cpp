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

const int MAXN = 2e5+5;
vector<int> adj[MAXN];

int distances[MAXN];
bool seen[MAXN];
int parents[MAXN];

int bfs(int start) {
    memset(distances, 0, sizeof(distances));
    memset(seen, 0, sizeof(seen));
    memset(parents, 0, sizeof(parents));

    queue<int> q;
    q.push(start);
    seen[start] = true;
    int last = start;

    while (!q.empty()) {
        int a = q.front(); q.pop();

        for (int b : adj[a]) {
            if (!seen[b]) {
                seen[b] = true;
                distances[b] = distances[a] + 1;
                q.push(b);
                parents[b] = a;
            }
        }

        last = a;
    }

    return last;
}

int walkBack(int start, int steps) {
    while (steps--) {
        start = parents[start];
    }

    return start; 
}

int main() {
	SPEED;
    int n;
    cin >> n;

    REP(i, n-1) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int v2 = bfs(1);
    int v3 = bfs(v2);
    cout << walkBack(v3, ceil((float)distances[v3]/2)) << endl;    
}
