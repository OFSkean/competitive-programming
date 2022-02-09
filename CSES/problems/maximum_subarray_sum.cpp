// solution for https://cses.fi/problemset/task/1643
// implementation of kadane's algorithm that doesn't allow for empty subset

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 

int main() {
	SPEED;
	int n;
	vector<ll> v;
	cin >> n;
	
	bool seenPositive = false;
	ll maximum = (ll) -10e9 - 7;
	
	for (int i = 0; i < n; i++) {
		ll q;
		cin >> q;
		v.push_back(q);
		
		seenPositive = seenPositive || (q >= 0);
		maximum = max(maximum, q);
	}
	
	if (!seenPositive) {
		cout << maximum << endl;
		exit(0);
	}
	
	ll best = 0; ll current = 0;
	for (int i = 0; i < n; i++) {
		current = max((ll) 0, current+v[i]);
		best = max(current, best);
	}
	
	cout << best << endl;
}
