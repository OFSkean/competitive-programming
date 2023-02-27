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

int main() {
	SPEED;
	
	int n;
	cin >> n;
	
	vector<int> nums(n+1);
	REP(i, n) {
		int q;
		cin >> q;
		nums[q] = i;
	}
	
	int numpasses=1;
	FOR(i, 1, n) {
		if (nums[i+1] < nums[i]) numpasses++;
	}
	
	cout << numpasses << endl;
}
