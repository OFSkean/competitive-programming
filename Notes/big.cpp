// TWO COLORING 
int n;
vector<vector<int>> adj;

//read in edges

vector<int> side(n, -1);
bool is_bipartite = true;
queue<int> q;
for (int st = 0; st < n; ++st) {
    if (side[st] == -1) {
        q.push(st);
        side[st] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : adj[v]) {
                if (side[u] == -1) {
                    side[u] = side[v] ^ 1;
                    q.push(u);
                } else {
                    is_bipartite &= side[u] != side[v];
                }
            }
        }
    }
}

cout << (is_bipartite ? "YES" : "NO") << endl;

// KOSARAJU

vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order, component;

void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}

int main() {
    int n;
    // ... read n ...

    for (;;) {
        int a, b;
        // ... read next directed edge (a,b) ...
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    used.assign(n, false);

    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);

    used.assign(n, false);
    reverse(order.begin(), order.end());

    for (auto v : order)
        if (!used[v]) {
            dfs2 (v);

            // ... processing next component ...

            component.clear();
        }
}

//FordFulkerson
int n;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

//min cost flow
//finds cheapest flow from s to t with certain value K
//O(n^2 m^2)
struct Edge
{
    int from, to, capacity, cost;
};

vector<vector<int>> adj, cost, capacity;

const int INF = 1e9;

void shortest_paths(int n, int v0, vector<int>& d, vector<int>& p) {
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<int> q;
    q.push(v0);
    p.assign(n, -1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

int min_cost_flow(int N, vector<Edge> edges, int K, int s, int t) {
    adj.assign(N, vector<int>());
    cost.assign(N, vector<int>(N, 0));
    capacity.assign(N, vector<int>(N, 0));
    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }

    int flow = 0;
    int cost = 0;
    vector<int> d, p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF)
            break;

        // find max flow on that path
        int f = K - flow;
        int cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }

        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }

    if (flow < K)
        return -1;
    else
        return cost;
}

//Bipartite Matching
int n, k;
vector<vector<int>> g;
vector<int> mt; //keeps track of left side edge connections
vector<bool> used;

bool try_kuhn(int v) {
    if (used[v])
        return false;
    used[v] = true;
    for (int to : g[v]) {
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int main() {
    // ... reading the graph ...

    mt.assign(k, -1);
    vector<bool> used1(n, false);
    for (int v = 0; v < n; ++v) {
        for (int to : g[v]) {
            if (mt[to] == -1) {
                mt[to] = v;
                used1[v] = true;
                break;
            }
        }
    }
    for (int v = 0; v < n; ++v) {
        if (used1[v])
            continue;
        used.assign(n, false);
        try_kuhn(v);
    }

    for (int i = 0; i < k; ++i)
        if (mt[i] != -1)
            printf("%d %d\n", mt[i] + 1, i + 1);
}

// 2SAT
// looks for scc with kosaraju
int n;
vector<vector<int>> adj, adj_t;
vector<bool> used;
vector<int> order, comp;
vector<bool> assignment;

void dfs1(int v) {
    used[v] = true;
    for (int u : adj[v]) {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int cl) {
    comp[v] = cl;
    for (int u : adj_t[v]) {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}

bool solve_2SAT() {
    order.clear();
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs1(i);
    }

    comp.assign(n, -1);
    for (int i = 0, j = 0; i < n; ++i) {
        int v = order[n - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }

    assignment.assign(n / 2, false);
    for (int i = 0; i < n; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}

void add_disjunction(int a, bool na, int b, bool nb) {
    // na and nb signify whether a and b are to be negated 
    a = 2*a ^ na;
    b = 2*b ^ nb;
    int neg_a = a ^ 1;
    int neg_b = b ^ 1;
    adj[neg_a].push_back(b);
    adj[neg_b].push_back(a);
    adj_t[b].push_back(neg_a);
    adj_t[a].push_back(neg_b);
}

// dynamic tsp
#include<iostream>
using namespace std;
#define MAX 9999
int n=4; // Number of the places want to visit
 //Next distan array will give Minimum distance through all the position
int distan[10][10] = {                
                    {0, 10, 15, 20},
                    {10, 0, 35, 25},
                    {15, 35, 0, 30},
                    {20, 25, 30, 0}
};
int completed_visit = (1<<n) - 1;
int DP[16][4];

int  TSP(int mark,int position){
  if(mark==completed_visit){      // Initially checking whether all
                                  // the places are visited or not
    return distan[position][0];
  }
  if(DP[mark][position]!=-1){
     return DP[mark][position];
  }
  //Here we will try to go to every other places to take the minimum
  // answer
  int answer = MAX;
  //Visit rest of the unvisited cities and mark the . Later find the 
  //minimum shortest path
  for(int city=0;city<n;city++){
    if((mark&(1<<city))==0){
      int newAnswer = distan[position][city] + TSP( mark|(1<<city),city);
      answer = min(answer, newAnswer);
    }
  }
  return DP[mark][position] = answer;
}
int main(){
    /* initialize the DP array */
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            DP[i][j] = -1;
        }
    }
	cout<<"Minimum Distance Travelled by you is "<<TSP(1,0);
	return 0;
}

// lca
int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

//hamiltonian path
#include <bits/stdc++.h>
using namespace std;
const int N = 5;

// Function to check whether there
// exists a Hamiltonian Path or not
bool Hamiltonian_path(
	vector<vector<int> >& adj, int N)
{
	int dp[N][(1 << N)];

	memset(dp, 0, sizeof dp);
	for (int i = 0; i < N; i++)
		dp[i][(1 << i)] = true;

	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < N; j++) {
			// if node is included in subset
			if (i & (1 << j)) {
				for (int k = 0; k < N; k++) {
					if (i & (1 << k)
						&& adj[k][j]
						&& j != k
						&& dp[k][i ^ (1 << j)]) {

						dp[j][i] = true;
						break;
					}
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (dp[i][(1 << N) - 1])
			return true;
	}

	// Otherwise, return false
	return false;
}

int main()
{
	vector<vector<int> > adj = { { 0, 1, 1, 1, 0 },
								{ 1, 0, 1, 0, 1 },
								{ 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 0, 0 } };
	int N = adj.size();
	if (Hamiltonian_path(adj, N))
		cout << "YES";
	else
		cout << "NO";

	return 0;
}

// LCS
#include <iostream>
#include <string>
using namespace std;
 
int LCSLength(string X, string Y)
{
    int m = X.length(), n = Y.length();
 
    int lookup[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        lookup[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        lookup[0][j] = 0;
    }
 
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1]) {
                lookup[i][j] = lookup[i - 1][j - 1] + 1;
            }
            else  {
                lookup[i][j] = max(lookup[i - 1][j], lookup[i][j - 1]);
            }
        }
    }
 
    return lookup[m][n];
}
 
int main()
{
    string X = "XMJYAUZ", Y = "MZJAWXU";
 
    cout << "The length of the LCS is " << LCSLength(X, Y);
 
    return 0;
}

//SCS
#include <iostream>
#include <string>
using namespace std;
 
int SCSLength(string X, string Y)
{
    int m = X.length(), n = Y.length();
 
    int lookup[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        lookup[i][0] = i;
    }
 
    for (int j = 0; j <= n; j++) {
        lookup[0][j] = j;
    }
 
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1]) {
                lookup[i][j] = lookup[i - 1][j - 1] + 1;
            }
   
            else {
                lookup[i][j] = min(lookup[i - 1][j] + 1, lookup[i][j - 1] + 1);
            }
        }
    }
  
    return lookup[m][n];
}
 
int main()
{
    string X = "ABCBDAB", Y = "BDCABA";
 
    cout << "The length of the shortest common supersequence is "
         << SCSLength(X, Y);
 
    return 0;
}

//edit distance
#include <iostream>
#include <cstring>
using namespace std;
 
int dist(string X, string Y)
{
    int m = X.length();
    int n = Y.length();
 
    int T[m + 1][n + 1];
 
    // initialize `T` by all 0's
    memset(T, 0, sizeof T);

    for (int i = 1; i <= m; i++) {
        T[i][0] = i;                // (case 1)
    }
 
    for (int j = 1; j <= n; j++) {
        T[0][j] = j;                // (case 1)
    }
 
    int substitutionCost;
 
    // fill the lookup table in a bottom-up manner
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1]) {                 // (case 2)
                substitutionCost = 0;                   // (case 2)
            }
            else {
                substitutionCost = 1;                   // (case 3c)
            }
            T[i][j] = min(min(T[i - 1][j] + 1,          // deletion (case 3b)
                            T[i][j - 1] + 1),           // insertion (case 3a)
                T[i - 1][j - 1] + substitutionCost);    // replace (case 2 & 3c)
        }
    }
 
    return T[m][n];
}
 
int main()
{
    string X = "kitten", Y = "sitting";
 
    cout << "The Levenshtein distance is " << dist(X, Y);
 
    return 0;
}

// KNAPSACK

// n is number of items. W is maximum cost allowed
int knapsack(vector<int>& cost, vector<int>& value, int n, int W) {
	// helper[i][j] stores maximum value that can be attained
	// with weight <= j and using only a subset of the first i
	int T[n+1][W+1] = {};

	FOR(i, 1, n+1) {
		FOR(j, 1, W+1) {

			T[i][j] = T[i-1][j];
			if (j - cost[i-1] >= 0) {
				T[i][j] = max(T[i][j], 
					T[i-1][j-cost[i-1]] + value[i-1]);
			}
		}
	}

	return T[n][W];
}
//partition problem
// Returns true if there exists a subset of `array[0…n)` with the given sum
bool subsetSum(vector<int> const &nums, int sum)
{
    int n = nums.size();
 
    bool T[n + 1][sum + 1];
 
    for (int j = 1; j <= sum; j++) {
        T[0][j] = false;
    }
 
    for (int i = 0; i <= n; i++) {
        T[i][0] = true;
    }
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (nums[i - 1] > j) {
                T[i][j] = T[i - 1][j];
            }
            else {
                T[i][j] = T[i - 1][j] || T[i - 1][j - nums[i - 1]];
            }
        }
    }
 
    return T[n][sum];
}

// true if possible, false if not
bool partition(vector<int> const &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    return !(sum & 1) && subsetSum(nums, sum/2);
}
 
int main()
{
    // Input: a set of items
    vector<int> nums = { 7, 3, 1, 5, 4, 8 };
 
    if (partition(nums)) {
        cout << "Set can be partitioned";
    }
    else {
        cout << "Set cannot be partitioned";
    }
 
    return 0;
}

// ROD CUTTING
int rodCut(int price[], int n) {
    int T[n + 1];
 
    for (int i = 0; i <= n; i++) {
        T[i] = 0;
    }
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            T[i] = max(T[i], price[j - 1] + T[i - j]);
        }
    }
 
    return T[n];
}
 
int main()
{
    int price[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
 
    // rod length
    int n = 4;
 
    cout << "Profit is " << rodCut(price, n);
 
    return 0;
}

//WORD BREAK
bool wordBreak(unordered_set<string> const &dict, string word, vector<int> &lookup)
    int n = word.size();
 
    if (n == 0) {
		cout << 
        return true;
    }
    
    if (lookup[n] == -1) {
        lookup[n] = 0;
 
        for (int i = 1; i <= n; i++) {
            string prefix = word.substr(0, i);
 
            if (find(dict.begin(), dict.end(), prefix) != dict.end() &&
                wordBreak(dict, word.substr(i), lookup))
            {	
				cout << prefix << endl;
                return lookup[n] = 1;
            }
        }
    }
 
    // return solution to the current subproblem
    return lookup[n];
}
 
// Word Break Problem Implementation in C++
int main() {
    unordered_set<string> dict = { "this", "th", "is", "famous", "Word", "break",
            "b", "r", "e", "a", "k", "br", "bre", "brea", "ak", "problem" };
 
    // input string
    string word = "Wordbreakproblem";
 
    vector<int> lookup(word.length() + 1, -1);
 
    if (wordBreak(dict, word, lookup)) {
        cout << "The string can be segmented";
    }
    else {
        cout << "The string can't be segmented";
    }
 
    return 0;
}

// tilings
const int MOD = 1e9 + 7;

int dp[1 << 10][2];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	dp[0][0] = 1;
	for (int j = 0; j < m; j++) for (int i = 0; i < n; i++) {
		for (int mask = 0; mask < (1 << n); mask++) {
			dp[mask][1] = dp[mask ^ (1 << i)][0]; // Vertical/no tile
			if (i && !(mask & (1 << i)) && !(mask & (1 << i - 1))) // Horizontal tile
				dp[mask][1] += dp[mask ^ (1 << i - 1)][0];

			if (dp[mask][1] >= MOD) dp[mask][1] -= MOD;
		}
		for (int mask = 0; mask < (1 << n); mask++) dp[mask][0] = dp[mask][1];
	}
	cout << dp[0][0];
	return 0;
}

//balanced sequence
bool next_balanced_sequence(string & s) {
    int n = s.size();
    int depth = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '(')
            depth--;
        else
            depth++;

        if (s[i] == '(' && depth > 0) {
            depth--;
            int open = (n - i - 1 - depth) / 2;
            int close = n - i - 1 - open;
            string next = s.substr(0, i) + ')' + string(open, '(') + string(close, ')');
            s.swap(next);
            return true;
        }
    }
    return false;
}

//convex hull
struct pt {
    double x, y;
};

int orientation(pt a, pt b, pt c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool ccw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o > 0 || (include_collinear && o == 0);
}

void convex_hull(vector<pt>& a, bool include_collinear = false) {
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.x, a.y) < make_pair(b.x, b.y);
    });
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2, include_collinear)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i], include_collinear))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2, include_collinear)) {
            while (down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i], include_collinear))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    if (include_collinear && up.size() == a.size()) {
        reverse(a.begin(), a.end());
        return;
    }
    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}

// josephus

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define int long long
#define endl '\n'

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    indexed_set s;
    int n,k; cin>>n>>k;
    for (int i = 1; i <= n; i++)
        s.insert(i);

    int ind = k%n;
    while(n--) {
        auto y = s.find_by_order(ind);
        cout<<*y<<' ';
        s.erase(y);
        if (n) ind = (ind%n + k)%n;
    }   
}
