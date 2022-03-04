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

void bfs(int start, int end) {
    queue<int> q;
    q.push(start);
    seen[start] = true;

    while (!q.empty()) {
        int a = q.front(); q.pop();
        
        //early break
        if (a == end) return;

        for (int b : adj[a]) {
            if (!seen[b]) {
                seen[b] = true;
                parents[b] = a;
                distances[b] = distances[a] + 1;
                q.push(b);
            }
        }
    }
}

//reconstruct the bfs route from parents array
void shortest_route(int start, int end) {
    //run bfs
    bfs(start, end);

    if (distances[end] == 0) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    
    // build route
    int length = distances[end];
    vector<int> route(length+1);
    
    int loc = end;
    for (int i = length; i >= 0; i--) {
        route[i] = loc;
        loc = parents[loc];
    }

    // print route
    cout << distances[end]+1 << endl;
    for(auto a : route) {
        cout << a << " ";
    }
    cout << endl;
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
    
    shortest_route(1, n);
}
