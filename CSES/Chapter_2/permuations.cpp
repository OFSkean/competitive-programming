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
	
	vector<int> permutation;
	for (int i = 0; i < n; i++) {
		permutation.push_back(i);
	}
	do {
		output_vector(permutation);
	} while (next_permutation(permutation.begin(), permutation.end()));
}
