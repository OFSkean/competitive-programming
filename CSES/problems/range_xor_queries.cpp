#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 

int main() {
	SPEED;
	int n , q;
	vector<int> s;
	cin >> n >> q;
	
	int prevBits = 0;
	for (int i = 0; i < n; i++) {
		ll k;
		cin >> k;
		
		prevBits ^= k;
		s.push_back(prevBits);
	}
	
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		if (l == 1) {cout << s[r-1] << endl;}
		else {cout << ((int) (s[r-1] ^ s[l-2])) << endl;}
	}
}
