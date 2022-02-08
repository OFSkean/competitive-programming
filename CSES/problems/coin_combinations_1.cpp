// solution for https://cses.fi/problemset/task/1635

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 
#define MAXN 1000005
#define MOD 1000000007

int main() {
	SPEED;
	ll c[MAXN] = {1};
	vector<int> d;
	int n, x;
	cin >> n >> x;
	
	for (int i = 0; i < n; i++) {
		int q;
		cin >> q;
		d.push_back(q);
	}
	sort(d.begin(), d.end());
	
	for (int i = 1; i <= x; i++) {
		for (auto coin : d) {
			if (i-coin >=0) {
				c[i] += c[i-coin];
				c[i] %= MOD;
			}
		}
	}
	cout << c[x] << endl;
}
