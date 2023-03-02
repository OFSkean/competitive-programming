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

const ll MOD = 1e9+7;
const ll MAXN = 1e5+2;
const ll MAXM = 102;
ll arr[MAXN][MAXM] = {0};

int main() {
	SPEED;
	int n, m;
	cin >> n >> m;
	
	
	int x;
	cin >> x;
	
	//bootstrap the first row
	if (x == 0) fill(arr, arr+102, (ll) 1);
	else arr[0][x] = 1;
	
	//do dp
	FOR (i, 1, n) {
		cin >> x;
		
		int upperbound = (x == 0) ? m+1 : x+1;
		
		FOR (j, min(1,(int) x), upperbound) {
			ll minusone = (i > 0 && j > 1) ? arr[i-1][j-1]: 0;
			ll same = (i > 0) ? arr[i-1][j] : 0;
			ll plusone = (i > 0 && j < m) ? arr[i-1][j+1]: 0;
			
			arr[i][j] = (minusone + same + plusone);
			arr[i][j] %= MOD;
		}
	}
	
	//find total of last row
	ll summation = 0;
	FOR(j, 1, m+1) {
		summation += arr[n-1][j];
		summation %= MOD;
	}
	
	cout << summation << endl;
}
