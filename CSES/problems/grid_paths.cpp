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

int num_solutions = 0;
string t;
bool grid[9][9] = {0};

void solve(int turn, int x, int y) {
	if (turn == 48 && (x==7 && y==1)) {
		num_solutions += 1;  //add two for symmetry optimization
		return;
	}
	
	// early breaks
	if (turn >= 48) return;
	if (grid[x][y]) return;  //already visited
	if (x==7 && y==1) return;  //got to end prematurely 
	if (grid[x-1][y] && grid[x+1][y] && !grid[x][y-1] && !grid[x][y+1]) return;  //xaxis bottom wall split
	if (!grid[x-1][y] && !grid[x+1][y] && grid[x][y-1] && grid[x][y+1]) return;  //yaxis bottom wall split
	
	grid[x][y] = 1; //visit current node
	
	// just keep travelling
	char next_move = t[turn];
	if (next_move == '?') {
		if (!grid[x+1][y]) solve(turn+1, x+1, y);
		if (!grid[x-1][y]) solve(turn+1, x-1, y);
		if (!grid[x][y-1]) solve(turn+1, x, y-1);
		if (!grid[x][y+1]) solve(turn+1, x, y+1);
	}
	else if (next_move == 'D') {
		if (!grid[x+1][y]) solve(turn+1, x+1, y);
	}
	else if (next_move == 'U') {
		if (!grid[x-1][y]) solve(turn+1, x-1, y);
	}
	else if (next_move == 'L') {
		if (!grid[x][y-1]) solve(turn+1, x, y-1);
	}
	else if (next_move == 'R') {
		if (!grid[x][y+1]) solve(turn+1, x, y+1);
	}
	
	grid[x][y] = 0; //unvisit current node
}

int main() {
	SPEED;
	cin >> t;
	
	REP(i, 9) {
		grid[i][8] = 1;
		grid[i][0] = 1;
		grid[0][i] = 1;
		grid[8][i] = 1;
	}
	
	solve(0, 1, 1);
	cout << num_solutions << endl;
}
