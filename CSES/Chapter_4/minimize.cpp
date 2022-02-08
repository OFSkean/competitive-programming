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

// minimizing |a_i - x|, find x
int main() {
	SPEED;
	
	int num;
	vector<int> v;
	while (cin >> num) {
		v.push_back(num);
	}
	
	sort(v.begin(), v.end());
	
	int x = v[v.size() / 2];
	int sum = 0;
	for (int i =0; i<v.size(); i++) {
		sum += abs(v[i] - x);
	}
	cout << sum << endl;
}
