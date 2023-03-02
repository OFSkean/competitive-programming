#include "template.h"
#include "graph.h"

int main() {
	SPEED;
    int n, m;
    cin >> n >> m;

    Graph g(n);

    REP(i, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        g.addEdge(a, b, c);
    }


    vector<ll> result = g.djikstra(1, n);
    FOR(i, 1, n+1) cout << result[i] << " ";
    cout << endl;    
}
