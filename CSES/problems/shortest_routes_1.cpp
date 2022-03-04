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

//use with edges of form <node, weight>
const int MAXN = 1e5+1;
vector<pair<int, ll>> adj[MAXN];
ll distances[MAXN];
bool seen[MAXN];

void djikstra(int start, int n) {
    FOR(i, 2, n+1) {
        distances[i] = LONG_MAX;
    }

    priority_queue<pair<ll, int>> q;
    q.push({0, start});

    while (!q.empty()) {
        int a = q.top().second; q.pop();
        
        if (!seen[a]) {
            seen[a] = true;
            for (auto e : adj[a]) {
                int b; ll w;
                tie(b, w) = e;
                
                if (distances[a]+w < distances[b]) {
                    distances[b] = distances[a]+w;
                    q.push({-distances[b], b});
                }
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
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

   djikstra(1, n);

   REP(i, n) {
        cout << distances[i+1] << " ";
   }
   cout << endl;
}
