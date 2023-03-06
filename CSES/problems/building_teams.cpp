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

    vector<int> colors = g.twoColor();

    if (colors[0] == 0) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        FOR(i, 1, n+1) {
            cout << colors[i]+1 << " ";
        }
        cout << endl;
    }
}
