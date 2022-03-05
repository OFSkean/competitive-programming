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

int edit_distance(string a, string b) {
	int m = a.length();
	int n = b.length();
	
	int T[m+1][n+1] = {};
	
	FOR(i, 1, m+1) {
		T[i][0] = i;
	}
	FOR(j, 1, n+1) {
		T[0][j] = j;
	}

	int cost = 0;
	FOR (i, 1, m+1) {
		FOR(j, 1, n+1) {
			if (a[i-1] == b[j-1]) cost = 0;
			else cost = 1;

			T[i][j] = min(min(T[i-1][j]+1, 
						  T[i][j-1]+1),
						  T[i-1][j-1] + cost);

		}
	}

	return T[m][n];
}

int main() {
	SPEED;
	string a, b;
	cin >> a >> b;
	cout << edit_distance(a, b) << endl;
}
