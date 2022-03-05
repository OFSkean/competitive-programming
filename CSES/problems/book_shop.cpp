#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)

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

int main() {
	SPEED;
	int n, x;
	cin >> n >> x;

	vector<int> c(n), v(n);
	
	REP(i, n) {
		cin >> c[i];
	}
	REP(i, n) {
		cin >> v[i];
	}
 		
	cout << knapsack(c, v, n, x) << endl;
}
