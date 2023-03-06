#include "template.h"
#include "graph.h"

int main() {
    SPEED;

    int n, m;
    cin >> n >> m;
	
	Graph g(n);
    REP(i, m) {
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b);
    }

    vector<ll> topo = g.topologicalSort();
	
	if (topo[0] == -1) {
		cout << "IMPOSSIBLE" << endl;
		exit(0);
	}

    for (auto it = topo.rbegin(); it != topo.rend(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
