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

const int MAXN = 1005;
int arr[MAXN][MAXN] = {0};
char grid[MAXN][MAXN];

void construct(int n) {
    FOR(i, 1, n+1) {
        FOR(j, 1, n+1) {
            arr[i][j] = arr[i-1][j] - arr[i-1][j-1] + arr[i][j-1] + (grid[i][j] == '*');
        }
    
    }
}

void query(int y1, int x1, int y2, int x2) {
    cout << arr[y2][x2] + arr[y1-1][x1-1] - arr[y2][x1-1] - arr[y1-1][x2] << endl;
}

int main() {
	SPEED;
    int n, q;
    cin >> n >> q;
    
    REP(i, n) {
        REP(j, n) {
            cin >> grid[i+1][j+1];
        }
    }

    construct(n);
    
    REP(i, q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        query(a, b, c, d);
    }
}
