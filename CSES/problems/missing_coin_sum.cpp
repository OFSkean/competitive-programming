#include <bits/stdc++.h>
using namespace std;

using cd = complex<double>;
const double PI = acos(-1);
#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i,a,b) for(ll i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)

void output_vector(vector<int> v) {
	for (auto i: v) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	SPEED;
	int n;
	cin >> n;
	
	vector<ll> coins(n);
	REP(i, n) {
		cin >> coins[i];
	}
	sort(all(coins));
	
	ll currentSum = 0;
	REP(i, n) {
		if (currentSum + 1 < coins[i]) break;
		currentSum += coins[i];
	}
	cout << currentSum + 1 << endl;
}
