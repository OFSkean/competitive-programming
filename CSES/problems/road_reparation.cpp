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

struct Edge {
	ll a, b, weight;
	bool operator<(Edge const& other) {
		return weight < other.weight;
	}
};

vector<Edge> edges;

int main() {
	SPEED;
	int n, e;
	cin >> n >> e;

	//read in edges	
	REP(i, e) {
		ll a, b, c;
		cin >> a >> b >> c;
		edges.push_back({a-1, b-1, c});
	}
	sort(edges.begin(), edges.end());

	//create node trees
	vector<int> tree_id(n);
	REP(i, n) {
		tree_id[i] = i;
	}

	int numEdges = 0;
	ll cost = 0;
	for (Edge e: edges) {
		if (tree_id[e.a] != tree_id[e.b]) {
			cost += e.weight;
			numEdges++;

			int old_id = tree_id[e.a], new_id = tree_id[e.b];
			REP(i, n) {
				if (tree_id[i] == old_id)
					tree_id[i] = new_id;
			}
		}
	}
	
	if (numEdges != (n-1)) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		cout << cost << endl;
	}
}
