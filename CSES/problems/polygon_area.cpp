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

int main() {
	SPEED;
	int n;
	cin >> n;
	
	vector<pair<ll,ll>> points;
	REP(i, n) {
		ll a, b;
		cin >> a >> b;
		points.pb(make_pair(a,b));
	}
	
	ll area = 0;
	FOR(i, 1, n) {
		area += (points[i-1].first - points[i].first) * (points[i].second + points[i-1].second);
	}
	area += (points[n-1].first - points[0].first) * (points[0].second + points[n-1].second);
	
	cout << abs(area) << endl;
}
