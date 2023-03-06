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
        g.addBiEdge(a, b);
    }
    
    auto path = g.listShortestPath(1, n);
    if (path[0] == -1) {
        cout << "IMPOSSIBLE" << endl;
        exit(0);
    }

    cout << path.size() << endl;
    output_vector(path);
}
