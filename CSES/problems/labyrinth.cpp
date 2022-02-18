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

const int MAXN = 1001;
bool m[MAXN][MAXN] = {0};
bool seen[MAXN][MAXN] = {0};

int previous[MAXN][MAXN];

pair<int, int> a;
pair<int, int> b;

// up down left right
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
string moves = "UDLR";

void bfs() {
	queue<pair<int, int>> q;
	q.push(a);
	
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		if (cur == b) {return;}
		
		REP(i, 4) {
			pair<int, int> n = make_pair(cur.first + dx[i], cur.second + dy[i]);
			if (n.first < 0 || n.first >= MAXN || n.second < 0 || n.second >= MAXN) continue;
			if (seen[n.first][n.second] || !m[n.first][n.second]) continue;
			
			seen[n.first][n.second] = 1;
			previous[n.first][n.second] = i;
			q.push(n);
		}
	}
}

int main() {
	SPEED;
	int h,w;
	cin >> h >> w;
	REP(i,h) {
		REP(j,w) {
			char q;
			cin >> q;
			
			if (q!='#') m[i][j] = 1;
			
			if (q == 'A') a = make_pair(i, j);
			else if (q == 'B') b = make_pair(i,j);
		}
	}
	
	bfs();
	if (seen[b.first][b.second]) {
		auto cur = b;
		string path;
		while (cur != a) {
			int direction = previous[cur.first][cur.second];
			cur = make_pair(cur.first - dx[direction], cur.second -dy[direction]);
			path += moves[direction];
		}
		reverse(path.begin(), path.end());
		cout << "YES" << endl;
		cout << path.size() << endl;
		cout << path << endl;
	}
	else {
		cout << "NO" << endl;
	}
}
