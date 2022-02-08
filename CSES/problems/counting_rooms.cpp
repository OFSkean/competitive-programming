// solution for https://cses.fi/problemset/task/1192

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 

const int MAXN = 1000;
bool seen[MAXN][MAXN] = {false};
bool m[MAXN][MAXN] = {false};

void dfs(int x, int y) {
	seen[x][y] = true;
	
	if (x > 0 && m[x-1][y] && !seen[x-1][y]) {
		dfs(x-1, y);
	}
	if (x < MAXN-1  && m[x+1][y] && !seen[x+1][y]) {
		dfs(x+1, y);
	}
	if (y > 0 && m[x][y-1] && !seen[x][y-1]) {
		dfs(x, y-1);
	}
	if (y < MAXN -1 && m[x][y+1] && !seen[x][y+1]) {
		dfs(x, y+1);
	}
}

int main() {
	SPEED;
	int n=0; int width =0;
	cin >> n >> width;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < width; j++) {
			char x;
			cin >> x;
			m[i][j] = true ? (x=='.') : false; 
		}
	}
	
	int numRooms = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < width; j++) {
			if (m[i][j] && !seen[i][j]) {
				dfs(i, j);
				numRooms++;
			}
		}
	}
	
	cout << numRooms << endl;
}
