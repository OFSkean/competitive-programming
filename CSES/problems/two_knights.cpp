#include <bits/stdc++.h>
using namespace std;

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
	
	cout << 0 << endl;
	FOR(k, 2, n+1) {
		ll numways = (k*k * (k*k - 1))/2 - 4*(k-1)*(k-2);
		cout << numways << endl; 
	}
}
