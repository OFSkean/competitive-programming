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

const int MAXLOG = 32;
const int MAXN = 200005;

int sparsetable[MAXLOG][MAXN] = {0};

// build sparse table
// note that position (i,j) stores the planet we get to starting at j after 2^i hops
// this technique is known as binary jumping (or binary lifting)
void construct(int n) {
	FOR(i, 1, MAXLOG) {
		FOR(j, 1, n+1) {
			sparsetable[i][j] = sparsetable[i-1][sparsetable[i-1][j]];
		}
	}
}

// query sparse table
// start at planet x and go k hops
void query(int x, int k) {
	int ans = x;
	
	int row = 0;
	while (k) {
		if (k & 1) {
			ans = sparsetable[row][ans];
		}
		
		row++;
		k >>=1;
	}

	cout << ans << endl;
}

int main() {
	SPEED;
	int n, q;
	cin >> n >> q;
	
	//read 1-hops directly into 0th row of sparse table
	REP(i, n) {
		// offset so that planet i goes into position i, not position i-1
		cin >> sparsetable[0][i+1];
	}
	
	construct(n);

	REP(i, q) {
		int x, k;
		cin >> x >> k;
		query(x, k);
	}
}
