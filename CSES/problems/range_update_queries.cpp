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
ll arr[MAXN];
ll n;

void query(ll pos) {
    ll sum = arr[pos];
    for (pos += n; pos > 0; pos >>= 1) {
        sum += seg[pos];
    }
    cout << sum << endl;
}

void update(ll l, ll r, ll val) {
    for (l += n, r+= n; l < r; l >>= 1, r >>= 1) {
        if (l&1) seg[l++] += val;
        if (r&1) seg[--r] += val;
    }
}

int main() {
	SPEED;
    int q;
    cin >> n >> q;
    
    REP(i, n) {
        cin >> arr[i];
    }

    REP(i, q) {
        ll a;
        cin >> a;
        
        if (a==2) {
            ll b;
            cin >> b;
            query(b-1);
        }
        else {
            ll b, c, d;
            cin >> b >> c >> d;
            update(b-1, c, d);
        }
    }

}
