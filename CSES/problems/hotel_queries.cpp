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

const int MAXN = 2e5 + 1;
ll seg[MAXN*2];
ll n;

void construct() {
    for (ll i = n-1; i > 0; i--) {
        seg[i] = max(seg[i<<1], seg[i<<1|1]);
    }
}

void update(ll pos, ll val) {
    for (seg[pos += n] = val; pos > 1; pos >>= 1) {
        seg[pos>>1] = max(seg[pos], seg[pos^1]);
    }
}

int query(ll key) {
	ll i = 1;
	if (seg[1] < key) {
		return 0;
	}
	cout << key << " ";
    while (i < n) {
		cout << i << " ";
		if (seg[i<<1] >= key) {
			i <<= 1;
		}
		else {
			i <<=1; i++;
		}
    }
	cout << i << endl;
	update(i-n, seg[i] - key);
    return i-n+1;
}

int main() {
	SPEED;
    int q;
    cin >> n >> q;
    REP(i, n) {
        cin >> seg[n+i];
    }

    construct();

    REP(i, q) {
        int h;
        cin >> h;
    cout << endl; 
	REP(i, 2*n) {
		cout << seg[i] << " ";
	}
	cout << endl;
        cout << query(h) << " ";
    }
	cout << endl;

}
