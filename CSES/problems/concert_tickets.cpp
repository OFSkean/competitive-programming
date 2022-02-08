// https://cses.fi/problemset/task/1091

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
	int n, m;
	vector<int> h, t;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int q;
		cin >> q;
		h.push_back(q);
	}
	
	for (int i = 0; i < m; i++) {
		int q;
		cin >> q;
		t.push_back(q);
	}
	
	sort(h.begin(), h.end());
	for (auto i : t) {
		int idx = binSearch(h, i);
		if (idx == -1 && h[0] <= i) {idx = 0;}
		if (idx == -1) {
			cout << -1 << endl;
		}
		else {
			cout << h[idx] << endl;
			h.erase(h.begin() + idx);
		}
	}
}
