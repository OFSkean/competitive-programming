#include "template.h"

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
    vector<vector<ll>> distances;
    ll n;

    public:
    static const ll bfn = 1e14;

    Graph(ll num_nodes) : adj(num_nodes+1, vector<Edge>(0)), distances(num_nodes+1, vector<ll>(num_nodes+1, (ll) bfn)), n(num_nodes+1) {}

    void addEdge(ll from, ll to, ll weight) {
        Edge new_edge = {from, to, weight};
        adj[from].pb(new_edge);
        distances[from][to] = min(distances[from][to], weight);
    }
    
    //computes sssp
    //needs non-negative weights
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
    vector<vector<ll>> floyd() {
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

    void printGraph() {
        for (auto node : adj) {
            for (auto edge : node) {
                cout << edge; 
            }
        }
    }
};
