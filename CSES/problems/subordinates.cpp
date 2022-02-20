#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)

int counts[200005] = {0};
vector<int> adj[200005];

void dfs(int start) {
	counts[start] = 1;
	for (int v : adj[start]) {
		dfs(v);
		counts[start] += counts[v];
	}
}

int main() {
	SPEED;
	int n;
	cin >> n;
		
	int b;
	FOR(i, 2, n+1) {
		cin >> b;
		
		adj[b].push_back(i);
	}
	
	dfs(1);
	
	FOR(i, 1, n+1) {
		cout << counts[i] -1 << " ";
	}
	cout << endl;
}
