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

vector<ll> t;
ll n, x, numways;

int main() {
	SPEED;
	cin >> n >> x;
	
	// gather the t's
	REP(i,n) {
		ll q;
		cin >> q;
		t.push_back(q);
	}
	sort(all(t));
	
	// keep track of partial sums of n/2 largest element combinations
    set<ll> psr;             //fast
    map<ll, ll> psr_counts;  //slow, use if multiple occurences in psr
    
    // note: do largest half here so that psr.size() is small. 
    // calculate partial sums of n/2 largest element combinations
    int num_in_upper_half = (n % 2) ? 1 + n/2 : n/2;
	REP(i, 1 << num_in_upper_half) {
		ll partial_sum = 0;
		REP(j, num_in_upper_half) {
			partial_sum += (i & 1<<j) ? t[n/2 + j] : 0;
		}
		
		if (partial_sum == x) numways++;
		else if (partial_sum < x) {
			ll rem = x - partial_sum;
			if (psr.count(rem)) {
				if (!psr_counts.count(rem)) psr_counts.insert(make_pair(rem,1));
				psr_counts[rem]++;
			}
			else {
				psr.insert(rem);
			}

		}
	} 
	
	cout << psr.size() << " " << psr_counts.size() << endl;
	// try to complete partial sums using n/2 smallest element combos
	REP(i, 1<<(n/2))  {
		ll partial_sum = 0;
		REP(j, n/2) {
			partial_sum += (i & 1<<j) ? t[j] : 0;
		}

		if (psr.count(partial_sum)) {numways += psr_counts.count(partial_sum) ?  psr_counts[partial_sum] : 1;}
	} 
	
	
	cout << numways << endl;
}
