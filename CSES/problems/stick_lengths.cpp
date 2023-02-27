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
	vector<ll> p;
	int n;
	cin >> n;
	REP(i, n) {
		ll p_i;
		cin >> p_i;
		p.pb(p_i);
	}
	sort(all(p));
	
	ll median = p[n/2];
	ll totalcost = 0;
	REP(i, n) {
		totalcost += abs(p[i] - median);
	}
	
	cout << totalcost << endl;
}
