#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 

void output_vector(vector<ll> v) {
	for (auto i: v) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	SPEED;
	int n , q;
	vector<ll> s;
	cin >> n >> q;
	
	ll prevSum = 0;
	for (int i = 0; i < n; i++) {
		ll k;
		cin >> k;
		
		prevSum += k;
		s.push_back(prevSum);
	}
	
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		if (l == 1) {cout << s[r-1] << endl;}
		else {cout << s[r-1] - s[l-2] << endl;}
	}
}
