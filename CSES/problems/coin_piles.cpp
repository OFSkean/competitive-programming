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
	int t;
	cin >> t;
	
	REP(i, t) {
		ll a, b;
		cin >> a >> b;
		if (a < b) swap(a, b);
		
		bool possible = a <= 2*b;
		
		a %= 3;
		b %= 3;
		
		possible &= ((a+b) == 0) || ((a+b)==3 && a != b);
		cout << (possible ? "YES" : "NO") << endl;
	}
}
