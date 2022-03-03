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

const int MAXN = 1e5;

bool visited[MAXN] = {false};
vector<int> adj[MAXN];

void DFSUtil(int s) {
	visited[s] = true;
	REP(i, adj[s].size()) {
		if (!visited[adj[s][i]])
			DFSUtil(adj[s][i]);
	}
}

void DFS(int n) {
	REP(i, n) {
		if (!visited[i]) {
			if (i == 0) { 
				DFSUtil(i);
			}
			else {
				cout << "NO" << endl << i << " " << i+1 << endl;
				exit(0);
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
		adj[a-1].push_back(b-1);
	}

	DFS(n);

	cout << "YES" << endl;
}
