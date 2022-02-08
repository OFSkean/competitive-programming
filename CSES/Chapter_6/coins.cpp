#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 

#define MAXN 200000
#define INF 10000000

int main() {
	SPEED;
	
	int v[MAXN];
	int c[MAXN] = {0};
	int first[MAXN];
	
	int n, d;
	
	cin >> n >> d;
	for (int i = 0; i < d; i++) {
		int q;
		cin >> q;
		c[i] = q;
	}
	
	v[0] = 0;
	for (int i = 1; i <= n; i++) {
		v[i] = INF;
		for (int j = 0; j < d; j++) {
			if (i-c[j] >= 0 && v[i - c[j]] < v[i]) {
				v[i] = v[i-c[j]]+1;
				first[i] = c[j];
			}
		}
	}
	
	cout << v[n] << endl;
	while (n > 0) {
		cout << first[n] << " ";
		n -= first[n];
	}
	cout << endl;
	
}
