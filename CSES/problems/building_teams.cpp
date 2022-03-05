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

const int MAXN = 1e5 + 1;
vector<int> adj[MAXN];
vector<int> color(MAXN, -1);

bool colorgraph(int n) {
	bool is_bipartite = true;
	queue<int> q;
	FOR(i, 1, n+1) {
		if (color[i] == -1) {
			q.push(i);
			color[i] = 0;
				
			while (!q.empty()) {
				int v = q.front(); q.pop();
				
				for (int u : adj[v]) {
					if (color[u] == -1) {
						color[u] = color[v] ^ 1;
						q.push(u);
					}
					else {
						is_bipartite &= color[u] != color[v];	
					}
				}	
			}
		}	
	}

	return is_bipartite;
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

	bool res = colorgraph(n);
	if (!res) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		FOR(i, 1, n+1) {
			cout << color[i] + 1 << " ";
		}
		cout << endl;
	}
}
