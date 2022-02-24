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

//keeps track of 9*10^i
ll powers[19];

void calculate(ll q) {
	//find what digit our answer belongs to
	ll ans = 0;
	int s_idx = 0;
	
	FOR(i, 1, 19) {
		//check if we can safely jump to next order of magnitude
		ll adjustment = i*powers[i-1];
		
		if (q >= adjustment) {
			ans += powers[i-1];
			q -= adjustment;
		}
		
		else {
			ans += max((ll)0, q / i);
			if (q % i) ans++;
			
			s_idx = ans != 9 ? abs((q-1) % i) : 0;
			
			break;
		}
	}
	
	string s_ans = to_string(ans);
	cout << s_ans[s_idx] << endl;
}

void construct() {
	powers[0] = 9;
	FOR(i, 1, 19) {
		powers[i] = 10 * powers[i-1];
	}
}

int main() {
	SPEED;
	construct();
	ll n;
	cin >> n;
	while (cin >> n) {
		calculate(n);
	}
	
}
