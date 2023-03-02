#include "template.h"
#include "graph.h"

int main() {
	SPEED;
    int n, m, q;
    cin >> n >> m >> q;

    Graph g(n);

    REP(i, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        g.addEdge(a, b, c);
        g.addEdge(b, a, c);
    }
    
    FOR(i, 1, n+1) {
        g.addEdge(i,i,0);
    }


    vector<vector<ll>> result = g.floyd();
    REP(i, q) {
        int a, b; 
        cin >> a >> b;
        cout << ((result[a][b] < g.bfn) ? result[a][b] : -1) << endl;
    }
}
