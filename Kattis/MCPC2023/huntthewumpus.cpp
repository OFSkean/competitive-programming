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
	bool grid[10][10] = {0};
	vector<pair<ll,ll>> wumpus;
	ll seed;
	cin >> seed;

	while(sz(wumpus) < 4) {
		seed = seed + (seed / 13) + 15;
		
		ll x = (seed / 10) % 10;
		ll y = seed % 10;
		grid[x][y] = 1;
		if (find(all(wumpus), make_pair(x,y)) == wumpus.end()) {
			wumpus.pb(make_pair(x, y));
		}
	}
	int nummoves = 0;
	int scores = 0;
	int guess;
	while (cin >> guess) {
		nummoves++;

		ll gx = (guess / 10) % 10;
		ll gy = guess % 10;
	
		bool shouldprintdistance = false;	
		
		if (grid[gx][gy] == 1) {
			grid[gx][gy] = 0;
			cout << "You hit a wumpus!" << endl;
			wumpus.erase(find(all(wumpus), make_pair(gx, gy)));
			scores++;
			if (scores < 4) { 
				shouldprintdistance = true;
			}
		}
		else shouldprintdistance=true;

		if (shouldprintdistance) {
			ll lowestdistance = 1e9;
			REP(j, sz(wumpus)) {
				ll curdistance = abs(gx - wumpus[j].first) + abs(gy - wumpus[j].second);
				lowestdistance = min(lowestdistance, curdistance);
			}
			cout << lowestdistance << endl;
		}
	}

	cout << "Your score is " << nummoves << " moves." << endl;
}
