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
	int nf, nm;
	cin >> nf >> nm;
	vector<ll> fish(nf);
	vector<pair<ll, ll>> mongers(nm);
	
	REP(i, nf) {
		cin >> fish[i];
	}
	
	REP(i, nm) {
		ll a, b;
		cin >> a >> b;
		mongers[i] = make_pair(b, a);
	}
	sort(fish.rbegin(), fish.rend());
	sort(mongers.rbegin(), mongers.rend());
	
	ll summer = 0;
	int fp = 0; int  mp = 0;
	while (fp < nf && mp < nm) {
		summer += mongers[mp].first*fish[fp];
		mongers[mp].second--;
		
		if (mongers[mp].second <= 0) mp++;
		fp++;
	}
	
	cout << summer << endl;
}
