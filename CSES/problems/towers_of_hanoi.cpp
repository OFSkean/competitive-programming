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

vector<pair<int,int>> moves;

void hanoi(int d, int l, int m, int r) {
    if (d == 1) {
        moves.pb(make_pair(l, r));
        return;
    }

    else {
        hanoi(d-1, l, r, m);
        moves.pb(make_pair(l, r));
        hanoi(d-1, m, l, r);
    }
}

int main() {
	SPEED;
    int n;
    cin >> n;
    
    hanoi(n, 1, 2, 3);
    cout << moves.size() << endl;
    REP(i, moves.size()) {
        cout << moves[i].first << " " << moves[i].second << endl;
    }
}
