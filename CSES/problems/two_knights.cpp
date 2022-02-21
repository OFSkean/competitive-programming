#include <bits/stdc++.h>
using namespace std;

int n;
long long int c;
vector<int> column(1000, 0);
vector<int> diag1(1000, 0);
vector<int> diag2(1000, 0);

void countQueens(int y) {
	if (y == n) {
		c++;
		return;
	}
	for (int x = 0; x < n; x++) {
		if (column[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
		column[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
		countQueens(y+1);
		column[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
	}
}

int main() {
	cin >> n;
	countQueens(0);
	cout << c << endl;
	
}
