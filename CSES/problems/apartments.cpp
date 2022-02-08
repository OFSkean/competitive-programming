// solution for https://cses.fi/problemset/task/1084

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 

void output_vector(vector<int> v) {
	for (auto i: v) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	SPEED;
	ll m, n , k;
	vector<int> a, b;
	
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		int q;
		cin >> q;
		a.push_back(q);
	}
	
	for (int i = 0; i < m; i++) {
		int q;
		cin >> q;
		
		b.push_back(q);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	int p1 = 0; int p2 = 0; int num = 0;
	
	while (p1 < a.size() && p2 < b.size()) {
		if (abs(a[p1] - b[p2]) <= k) {p1++; p2++; num++;}
		else if (a[p1] < b[p2]) {p1++;}
		else {p2++;}
	}
	
	cout << num << endl;
	
}
