// https://cses.fi/problemset/task/1094

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 

int main() {
	SPEED;
	int n;
	vector<int> v;
	cin >> n;
	
	int x;
	while (cin >> x) {
		v.push_back(x);
	}
	
	ll sum = 0;
	for (auto i = 1U; i < v.size(); i++) {
		ll increment = max(0, v[i-1] - v[i]);
		sum += increment;
		v[i] += increment;
		
	}
	cout << sum << endl;
}
