// https://cses.fi/problemset/task/1083

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 

int main() {
	SPEED;
	int n, x;
	vector<int> a;
	cin >> n;
	
	while (cin >> x) {
		a.push_back(x);
	}
	a.push_back(1e7);
	
	sort(a.begin(), a.end());
	
	for (auto i = 0; i < n; i++) {
		if (a[i] != (i+1)) {
			cout << i+1 << endl;
			break;
		}
	}
}
