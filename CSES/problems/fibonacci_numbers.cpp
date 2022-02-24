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

const ll MOD = 1e9 + 7;

// represents 2d matrix of the form
// x_00 x_01
// x_10 x_11
struct mat {
	ll x_00, x_01, x_10, x_11;
	
	mat operator *(const mat &b) {
		ll ux_00 = (x_00 * b.x_00 + x_01 * b.x_10) % MOD;
		ll ux_01 = (x_00 * b.x_01 + x_01 * b.x_11) % MOD;
		ll ux_11 = (x_10 * b.x_01 + x_11 * b.x_11) % MOD;
		
		mat result = {ux_00, ux_01, ux_01, ux_11};
		return result;
	}
};

// returns the nth fibonacci number
// uses matrix form and binary exponentiation
ll fibonacci_binpow(ll n) {
	mat start = {1, 1, 1, 0};
	mat result = {1, 1, 1, 0};
	
	// do binary exponentation
	while (n) {
		if (n & 1) {
			result = result * start;
		}
		start = start * start;
		
		// shift n 1-bit to the right
		n >>= 1;
	}

	return result.x_00;
}

int main() {
	SPEED;
	ll n;
	cin >> n;
	
	if (n < 2) {
		cout << n << endl;
		exit(0);
	} 
	
	// note that we use n-2 because the start matrix starts at n=2	
	cout << fibonacci_binpow(n-2) << endl;
}
