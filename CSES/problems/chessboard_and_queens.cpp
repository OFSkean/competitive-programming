#include <bits/stdc++.h>
using namespace std;

using cd = complex<double>;
const double PI = acos(-1);
#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i,a,b) for(ll i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)


const int MAXSIZE = 8;
int num_solutions = 0;
bool arr[MAXSIZE][MAXSIZE] = {0};
bool col[MAXSIZE] = {0}; bool diag1[2*MAXSIZE] = {0}; bool diag2[2*MAXSIZE] = {0};

void solve(int y) {
	if (y == MAXSIZE) {
		cout << num_solutions << endl;
		num_solutions++;
		return;
	}
	
	REP(x, MAXSIZE) {
		if (col[x] || diag1[x+y] || diag2[x-y+MAXSIZE-1] || !arr[y][x]) continue;
		col[x] = diag1[x+y] = diag2[x-y+MAXSIZE-1] = 1;
		solve(y+1);
		col[x] = diag1[x+y] = diag2[x-y+MAXSIZE-1] = 0;
	}
}

int main() {
	SPEED;
	
	REP(i, MAXSIZE) {
		REP(j, MAXSIZE) {
			char c;
			cin >> c;
			arr[i][j] = c=='*' ? 0 : 1;
		}
	}
	
	solve(0);
	cout << num_solutions << endl;
}
