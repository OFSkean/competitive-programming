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
	int n;
	cin >> n;
	for (int b = 0; b<(1<<n); b++) {
		vector<int> subset;
		for (int i =0; i<n; i++) {
			if (b&(1<<i)) subset.push_back(i);
		}
		
		// do stuff with subset vector
		output_vector(subset);
	}
}
