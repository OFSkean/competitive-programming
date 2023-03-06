#include "template.h"
#include "unionfind.h"

typedef struct edge
{
	ll from;
	ll to;
	ll weight;

} Edge;

// todo: doing > in comparison for djikstra. should move this elsewhere
bool operator < (const Edge& a, const Edge& b) {return a.weight > b.weight;}

ostream& operator<<(ostream& os, const Edge& edge) {
	return os << "From: " << edge.from << " "
		<< "To: " << edge.to << " "
		<< "Weight: " << edge.weight << endl;
}

class Graph {
	vector<vector<Edge>> adj;
	ll n;

	public:
	static const ll bfn = 1e14;

	Graph(ll num_nodes) : adj(num_nodes+1, vector<Edge>(0)), n(num_nodes+1) {}

	void addEdge(ll from, ll to, ll weight) {
		Edge new_edge = {from, to, weight};
		adj[from].pb(new_edge);
	}

	//computes sssp
	//needs non-negative weights
	//O(E + VlogV)
	vector<ll> djikstra(ll start, ll end) {
		bool seen[this->n] = {false} ;
		vector<ll> distances(this->n, (ll) LONG_MAX);
		distances[start] = 0;

		priority_queue<Edge> q;
		q.push({start, start, 0});

		while (!q.empty()) {
			Edge a = q.top(); q.pop();

			if (!seen[a.to]) {
				seen[a.to] = true;

				for (Edge b : adj[a.to]) {
					if (distances[b.from] + b.weight < distances[b.to]) {
						distances[b.to] = distances[b.from] + b.weight;
						q.push({b.from, b.to, distances[b.to]});
					}
				}
			}
		}

		return distances;
	}

	//computes apsp
	//needs no negative cycles
	//O(V^3)
	vector<vector<ll>> floyd() {
		vector<vector<ll>> distances(n, vector<ll>(n, (ll) bfn));

		FOR(i, 1, n) {
			for (auto e: adj[i]) {
				distances[e.from][e.to] = min(distances[e.from][e.to], e.weight);
			}
		}

		FOR(k, 1, n) {
			FOR(i, 1, n) {
				FOR(j, 1, n) {
					distances[i][j] = min(distances[i][j], 
							distances[i][k] + distances[k][j]);
				}
			}
		}

		return distances;
	}

	//computes mst
	//O(E log V) (log V instead of log E due to union-find)
	ll kruskal() {
		//collect all edges and sort them
		vector<Edge> edges;
		REP(i, n) {
			for (auto e: adj[i]) edges.pb(e);
		}
		sort(all(edges));
		reverse(all(edges));

		//initialize unionfind
		UnionFind uf(n);
		FOR(i, 0, n) {
			uf.make_set(i);
		}

		// perform kruskal
		ll cost = 0;
		vector<pair<int,int>> result;
		for (auto e : edges) {
			if (uf.find_set(e.from-1) != uf.find_set(e.to-1)) {
				cost += e.weight;
				result.push_back({e.from, e.to});
				uf.union_sets(e.from-1, e.to-1);
			}
		}

		//return MST edge set
		//if (return_edges) return edges;

		//return MST cost
		if ((int) result.size() < n-2) return -1;
		return cost;
	}


	//performs a dfs starting from a given node
	//optional function argument that gets called on each visit
	//uses discovered/finished times ala CLRS book
	template<typename F, typename G>
		void dfs(ll start, vector<bool>& seen, vector<bool>& finished, F* visit_func, G* cycle_func) {
			if (finished[start]) return;
			else if (seen[start]) {(*cycle_func)(start); return;}

			seen[start] = true;
			for (auto e: adj[start]) {
				dfs(e.to, seen, finished, visit_func, cycle_func);
			}

			seen[start] = false;
			finished[start] = true;
			(*visit_func)(start);
		}

	//computes the dfs forest
	template<typename F, typename G, typename H>
		void dfsall(F* visit_func, G* cycle_func, H* dfstree_func) {	
			vector<bool> seen(n);
			vector<bool> finished(n);

			FOR(i, 1, n) {
				if (!finished[i]) {
					dfs(i, seen, finished, visit_func, cycle_func);
					(*dfstree_func)(i);
				}
			}
		}
    template<typename F, typename G>	
		void dfsall(F* visit_func, G* cycle_func) {
			dfsall(visit_func, cycle_func, new NOOP);
		}	

	//computes the topological sort
	//checks for cycle along the way
	vector<ll> topologicalSort() {
		bool hasCycle = false;
		vector<ll> sorted;

		auto cycleDetect = [&hasCycle](ll seenNode) {hasCycle = true;};
		auto pushFinishedNode = [&sorted](ll seenNode) {sorted.pb(seenNode);};

		dfsall(&pushFinishedNode, &cycleDetect);

		if (hasCycle) return {-1};
		return sorted;
	}

	void printGraph() {
		for (auto node : adj) {
			for (auto edge : node) {
				cout << edge; 
			}
		}
	}
};

