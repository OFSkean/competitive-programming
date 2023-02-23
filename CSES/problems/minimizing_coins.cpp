
// https://cses.fi/problemset/submit/1634/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 
#define MAXN 1000005
#define INF 100000000
int main() {
	SPEED;
	int n, x;
	int c[100];
	int v[MAXN] = {0};
	cin >> n >> x;
	
	for (int i = 0; i < n; i++) {
		int q;
		cin >> q;
		c[i] = q;
	}
	
	for (int i = 1; i <= x; i++) {
		v[i] = INF;
		for (int j = 0; j < n; j++) {
			if (i-c[j] >= 0) {
				v[i] = min(v[i], v[i-c[j]]+1);
			}
		}
	}
	
	cout << (v[x] == INF ? -1 : v[x]) << endl;
	
}
