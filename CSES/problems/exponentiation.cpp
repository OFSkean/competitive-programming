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

const ll MOD = (ll) 1e9 + 7;

void exponentiation(ll a, ll b) {
	ll val = 1;
	while (b > 0) {
        if (b & 1) {
		    val *= a;
		}
        a *= a;
        
        a %= MOD;
        val %= MOD;
        b >>= 1;
	}
	
	cout << val << endl;
}
int main() {
	SPEED;
	int n;
	cin >> n;
	REP(i, n) {
		ll a, b;
		cin >> a >> b;
		exponentiation(a,b);
	}
}
