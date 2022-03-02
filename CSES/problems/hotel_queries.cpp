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
        seg[i] = seg[i<<1]  + seg[i<<1|1];
    }
}

void update(ll pos, ll val) {
    for (seg[pos += n] = val; pos > 1; pos >>= 1) {
        seg[pos>>1] = seg[pos] + seg[pos^1];
    }
}

void query(ll l, ll r) {
    ll sum = 0;
    for (l += n, r+= n; l < r; l >>= 1, r >>= 1) {
        if (l&1) sum += seg[l++];
        if (r&1) sum += seg[--r];
    }
    cout << sum << endl;
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
        ll a, b, c;
        cin >> a >> b >> c;
      
        if (a==1) {
            b--;
            update(b, c);
        }
        else {
            b--;
            query(b, c);
        }
    }

}
