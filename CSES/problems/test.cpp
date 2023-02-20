// https://cses.fi/problemset/task/1623/

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

vector<ll> a;
vector<ll> subset;
int n;

int main() {
	SPEED;
	cin >> n;
	REP(i,n) {
		ll q;
		cin >> q;
		a.push_back(q);
	}
	
	ll total = accumulate(all(a), (ll) 0);
	
	// assign each apple a bit in a n-bit string
	// apple group is the value of the bit
	
	ll minimum = 10e13;
	REP(i, 1<<n) {
		ll group1sum = 0;
		REP(j, n) {
			group1sum += (i & 1<<j) ? a[n-1-j] : 0;
		}
		ll group0sum = total - group1sum;
		
		minimum = min(minimum, abs(group1sum - group0sum));
	} 
	
	cout << minimum << endl;
}
