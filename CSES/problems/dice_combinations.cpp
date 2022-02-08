// solution for https://cses.fi/problemset/task/1633

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 
#define MAXN 1000005
#define MOD 1000000007

int main() {
	SPEED;
	ll c[MAXN] = {1};
	int d[6] = {1,2,3,4,5,6};
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 6; j++) {
			if (i-d[j] >=0) {
				c[i] += c[i-d[j]];
				c[i] %= MOD;
			}
		}
	}
	cout << c[n] << endl;
}
