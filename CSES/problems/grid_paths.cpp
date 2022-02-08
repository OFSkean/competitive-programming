// solution for https://cses.fi/problemset/task/1625

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 

int n;
const int MAX = 10;
ll c = 0;

// OPT 3, forseeing impossible paths if hitting a wall
// 0 min 0.773 s
void opt3(bool seen[MAX][MAX], vector<pair<int, char>> m, int numVisited, int x, int y) {
	if ((x==n-1) && (y==n-1)) {
		if (numVisited == 48) c += 1;
		return;
	}
	
	if ((!m[numVisited] || m[numVisited] = 'L') && x>0) {
		
	}
	
}

void opt3(bool visited[MAX][MAX], int numVisited, int x, int y) {
	if ((x==n-1) && (y==n-1)) {
		if (numVisited == n*n) c += 1;
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
	string s;
	vector<int, char> v;
	cin >> s;
	
	for (int i = 0U; i < s.size(); i++) {
		if (s[i] != '?') {
			v.push_back(make_pair(i+1, s[i]));
		}
	}
	
	bool seen[MAX][MAX] = {0};
		
	opt3(seen, v, 1, 0 ,0);
	cout << c << endl;
}
