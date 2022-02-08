//https://cses.fi/problemset/task/1084

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 

void output_vector(vector<int> v) {
	for (auto i: v) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	SPEED;
	ll n, x;
	vector<int> a;
	
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		int q;
		cin >> q;
		a.push_back(q);
	}
	
	sort(a.begin(), a.end());
	
	ll p1 = 0; ll p2 = a.size() - 1; ll num = 0;
	while (p1 <= p2) {
		if ((p1 == p2) || (a[p1] + a[p2]) <= x ) {p1++; p2--; num++;}
		else {p2--; num++;}
	}
	
	cout << num << endl;
}
