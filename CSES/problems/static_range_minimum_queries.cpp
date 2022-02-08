#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 

#define MAXLOG 20
#define MAXN 200000
int sparse[MAXN][MAXLOG];
int logs[MAXN+1];

void construct(int n) {
	//build log table
	logs[1] = 0;
	for (int i = 2; i <= MAXN; i++) {
		logs[i] = logs[i/2] + 1;
	}

	//build sparse table
	for (int row = 1; row < MAXLOG; row++) {
		for (int i = 0; i + (1 << row) <= n; i++) {
			sparse[i][row] = min(sparse[i][row-1], sparse[i + (1 << (row-1))][row-1]);
		}
	}
}

int query(int l, int r) {
	int row = logs[r - l + 1];
	//cout << l << " " << r << " " << sparse[l][row] << " " <<  sparse[r - (1 << row) + 1][row] << endl;
	return min(sparse[l][row], sparse[r - (1 << row) + 1][row]);
}

int main() {
	SPEED;
	int n, q;
	cin >> n >> q;

	for (int i = 0; i < n; i++) {
		cin >> sparse[i][0];
	}

	construct(n);

	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		cout << query(a-1, b-1) << endl;
	}
}
