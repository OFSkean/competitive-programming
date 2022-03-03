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

int main() {
	SPEED;
	int n, k;
	cin >> n >> k;
	
	vector<ll> arr;
	REP(i, n) {
		ll x;
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());
	FOR(i, n) {
		
		ll start = i+1;
		ll end = n-1;
		while (start < end) {
			ll summer = arr[i] + arr[start] + arr[end] 
			if (summer == k) {
				cout << arr[i] << " " << arr[start] << " " << arr[end];
				exit(0);
			}
			while (summer > k) {
				end--;
			}
			else 

			if 
		}
	}
}
