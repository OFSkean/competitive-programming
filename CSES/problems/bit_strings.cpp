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

const ll MOD = 1e9 + 7;

int main() {
	SPEED;
    ll n;
    cin >> n;
    ll ans = 2;
    FOR(i, 1, n) {
        ans *= 2;
        ans %= MOD;
    }

    cout << ans << endl;
}
