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

const int MAXN = 505;
const ll bfn = 1e14;

ll distances[MAXN][MAXN];

void floyd(int n) {
    FOR(k, 1, n+1) {
        FOR(i, 1, n+1) {
            FOR(j, 1, n+1) {
                distances[i][j] = min(distances[i][j], 
                        distances[i][k] + distances[k][j]);
            }
        }
    }
}

int main() {
	SPEED;
    int n,m,q;
    cin >> n >> m >> q;
    
    // prepare distances matrix
	REP(i, n+1) {
		REP(j, n+1) {
            distances[i][j] = bfn;
        }
    }
    REP(i, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        
        distances[a][a] = 0; distances[b][b] = 0;
        distances[a][b] = distances[b][a] = min(distances[a][b], c);
    }

    floyd(n);

    REP(i, q) {
        int a, b;
        cin >> a >> b;
        ll res = distances[a][b];
        cout << (res < bfn ? res : -1) << endl;
    }
}
