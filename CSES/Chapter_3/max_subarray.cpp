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
	vector<int> a;
	int n;
	
	cin >> n;
	for (int i =0; i < n; i++) {
		int q;
		cin >> q;
		a.push_back(q);
	}
	
	int best=0, sum = 0;
	for (int k = 0; k < n; k++) {
		sum = max(a[k], sum+a[k]);
		best = max(best, sum);
	}
	
	cout << best << endl;
	
}
