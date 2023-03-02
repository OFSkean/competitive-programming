#include "template.h"

typedef struct edge
{
    ll from;
    ll to;
    ll weight;

} Edge;

// todo: doing > in comparison for djikstra. should move this elsewhere
bool operator < (const Edge& a, const Edge& b) {return a.weight < b.weight;}

ostream& operator<<(ostream& os, const Edge& edge) {
    return os << "From: " << edge.from << " "
        << "To: " << edge.to << " "
        << "Weight: " << edge.weight << endl;
}

class Graph {
    vector<vector<Edge>> adj;
    ll n;

    public:
    Graph(ll num_nodes) : adj(num_nodes+1, vector<Edge>(0)), n(num_nodes) {}

    void addEdge(ll from, ll to, ll weight) {
        Edge new_edge = {from, to, weight};
        adj[from].pb(new_edge);
    }

    vector<ll> djikstra(ll start, ll end) {
        bool seen[this->n+1] = {false} ;
        vector<ll> distances(this->n+1, (ll) LONG_MAX);
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
                        q.push(b);
                    }
                }
            }
        }
        int summation = 0;  
        FOR(i, 1, this->n+1) {summation += seen[i]; cout << seen[i] << " " ;}
        cout << summation << endl;      
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
