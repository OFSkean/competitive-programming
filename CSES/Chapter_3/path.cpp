#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 

int n;
const int MAX = 10;
ll c = 0;

// Basic implementation with no optimization
// 2 min 54 s
void basic(bool visited[MAX][MAX], int numVisited, int x, int y) {
	if ((x==n-1) && (y==n-1) && (numVisited == n*n)) {
		c++;
		return;
	}

	if (x>0 && !visited[x-1][y]) {
		visited[x][y] = 1;
		basic(visited, numVisited+1, x-1, y);
		visited[x][y] = 0;
	}
	
	if (x<n-1 && !visited[x+1][y]) {
		visited[x][y] = 1;
		basic(visited, numVisited+1, x+1, y);
		visited[x][y] = 0;
	}
	
	if (y>0 && !visited[x][y-1]) {
		visited[x][y] = 1;
		basic(visited, numVisited+1, x, y-1);
		visited[x][y] = 0;
	}
	
	if (y<n-1 && !visited[x][y+1]) {
		visited[x][y] = 1;
		basic(visited, numVisited+1, x, y+1);
		visited[x][y] = 0;
	}
}

// OPT 1, use symmetry. NOTE: we increment count twice because otherwise c will be exactly 1/2 of true value
// 1 min 28 s
void opt1(bool visited[MAX][MAX], int numVisited, int x, int y) {
	if ((x==n-1) && (y==n-1) && (numVisited == n*n)) {
		c += 2;
		return;
	}
	
	if (x>0 && !visited[x-1][y]) {
		visited[x][y] = 1;
		opt1(visited, numVisited+1, x-1, y);
		visited[x][y] = 0;
	}
	
	if (x<n-1 && !visited[x+1][y] && !(x==0 && y==0)) {
		visited[x][y] = 1;
		opt1(visited, numVisited+1, x+1, y);
		visited[x][y] = 0;
	}
	
	if (y>0 && !visited[x][y-1]) {
		visited[x][y] = 1;
		opt1(visited, numVisited+1, x, y-1);
		visited[x][y] = 0;
	}
	
	if (y<n-1 && !visited[x][y+1]) {
		visited[x][y] = 1;
		opt1(visited, numVisited+1, x, y+1);
		visited[x][y] = 0;
	}
}

// OPT 2, early stop if corner reached
// 0 min 49 s
void opt2(bool visited[MAX][MAX], int numVisited, int x, int y) {
	if ((x==n-1) && (y==n-1)) {
		if (numVisited == n*n) c += 2;
		return;
	}
	
	if (x>0 && !visited[x-1][y]) {
		visited[x][y] = 1;
		opt2(visited, numVisited+1, x-1, y);
		visited[x][y] = 0;
	}
	
	if (x<n-1 && !visited[x+1][y] && !(x==0 && y==0)) {
		visited[x][y] = 1;
		opt2(visited, numVisited+1, x+1, y);
		visited[x][y] = 0;
	}
	
	if (y>0 && !visited[x][y-1]) {
		visited[x][y] = 1;
		opt2(visited, numVisited+1, x, y-1);
		visited[x][y] = 0;
	}
	
	if (y<n-1 && !visited[x][y+1]) {
		visited[x][y] = 1;
		opt2(visited, numVisited+1, x, y+1);
		visited[x][y] = 0;
	}
}


// OPT 3, forseeing impossible paths if hitting a wall
// 0 min 0.773 s
void opt3(bool visited[MAX][MAX], int numVisited, int x, int y) {
	if ((x==n-1) && (y==n-1)) {
		if (numVisited == n*n) c += 2;
		return;
	}
	
	if (x>0 && !visited[x-1][y]) {
		if ((y==0 || y==n-1) && x<n-1 && !visited[x+1][y]) return;
		
		visited[x][y] = 1;
		opt3(visited, numVisited+1, x-1, y);
		visited[x][y] = 0;
	}
	
	if (x<n-1 && !visited[x+1][y] && !(x==0 && y==0)) {
		if ((y==0 || y==n-1) && !(x==0 && y==0) && x>0 && !visited[x-1][y]) return;
		visited[x][y] = 1;
		opt3(visited, numVisited+1, x+1, y);
		visited[x][y] = 0;
	}
	
	if (y>0 && !visited[x][y-1]) {
		if ((x==0 || x==n-1) && !(x==0 && y==0) &&  y<n-1 && !visited[x][y+1]) return;
		visited[x][y] = 1;
		opt3(visited, numVisited+1, x, y-1);
		visited[x][y] = 0;
	}
	
	if (y<n-1 && !visited[x][y+1]) {
		if ((x==0 || x==n-1) && !(x==0 && y==0) && y>0 && !visited[x][y-1]) return;
		visited[x][y] = 1;
		opt3(visited, numVisited+1, x, y+1);
		visited[x][y] = 0;
	}
}

int main() {
	SPEED;
	
	cin >> n;
	
	bool v[MAX][MAX] = {0};
	opt3(v, 1, 0 ,0);
	cout << c << endl;
}
