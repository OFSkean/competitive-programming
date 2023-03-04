#include "template.h"
#include "graph.h"


int main() {
	SPEED;
    ll n, m;
    cin >> n >> m;

    Graph g(n);

    REP(i, m) {
        ll a,b, c;
        cin >> a >> b >> c;
        g.addEdge(a,b,c);
        g.addEdge(b,a,c);
    }
    
	ll cost = g.kruskal();
    	    
    if (cost == -1) cout << "IMPOSSIBLE";
    else cout << cost;
    cout << endl;
}
