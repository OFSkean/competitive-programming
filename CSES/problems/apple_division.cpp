// https://cses.fi/problemset/task/1623/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 

vector<ll> a;
vector<ll> subset;
int n;
ll minimum = 10e13;
ll total = 0;

void solve(int k) {
	if (k == n) {
		ll group = accumulate(subset.begin(), subset.end(), (ll) 0);
		minimum = min(minimum, abs(total -2*group));
		
	}
	else {
		solve(k+1);
		subset.push_back(a[k]);
		solve(k+1);
		subset.pop_back();	
	}
}

int main() {
	SPEED;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll q;
		cin >> q;
		total += q;
		a.push_back(q);
	}
	
	solve(0);
	cout << minimum << endl;
}
