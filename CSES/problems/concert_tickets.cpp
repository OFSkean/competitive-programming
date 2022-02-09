// https://cses.fi/problemset/task/1091

#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 

int main() {
	SPEED;
	int n, m;
	multiset<int> tickets;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int q;
		cin >> q;
		tickets.insert(q);
	}
	
	for (int i = 0; i < m; i++) {
		int g;
		cin >> g;
		auto it = tickets.upper_bound(g);
		if (it==tickets.begin()) {
			cout << -1 << endl;
		}
		else {
			cout << *(--it) << endl;
			tickets.erase(it);
		}
	}
}
