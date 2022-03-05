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

const int MOD = 1e9 + 7;
int counting(int n, int m) {
	int T[n+1][m+1] = {};
	
	FOR(i, 2, n+1) {
		FOR(j, 2, m+1) {
			T[i][j] = (T[i][j-2] + 1) * (T[i-1][j] + 1);
			T[i][j] %= MOD;
		}
	}
	
	return T[n][m];
}

int main() {
	SPEED;
	int n, m;
	cin >> n >> m;
	cout << counting(n,m) << endl;
}
