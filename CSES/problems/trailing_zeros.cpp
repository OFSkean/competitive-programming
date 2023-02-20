#include <bits/stdc++.h>
using namespace std;

using cd = complex<double>;
const double PI = acos(-1);
#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i,a,b) for(ll i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)

int main() {
	SPEED;
	ll n;
	cin >> n;
	
	ll num5factors = 0;
	ll curfactor = 5;
	while ((ll)(n / curfactor)) {
		num5factors += (ll)(n / curfactor);
		curfactor *= 5;
	}
	cout << num5factors << endl;
}
