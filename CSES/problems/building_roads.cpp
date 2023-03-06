#include "template.h"
#include "graph.h"

class RoadGraph : public Graph {
public:
	RoadGraph(int n) : Graph(n) {}

	vector<ll> buildRoads() {
		vector<ll> roadNodes;

		auto getRoadNodes= [&roadNodes](ll seenNode) {roadNodes.pb(seenNode);};
		dfsall(new NOOP, new NOOP, &getRoadNodes);

		return roadNodes;
	}
};

int main() {
	SPEED;
	int n, m;
	cin >> n >> m;

	RoadGraph g(n);

	REP(i, m) {
		int a, b;
		cin >> a >> b;
        g.addBiEdge(a,b);
	}

	auto newroads = g.buildRoads();

	cout << (sz(newroads)-1) << endl;
	REP(i, sz(newroads)-1) {
		cout << newroads[i] << " " << newroads[i+1] << endl;
	}
}
