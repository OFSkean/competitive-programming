// https://cses.fi/problemset/view/1621/

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 
 
int main() {
	SPEED;
	int n;
	vector<int> v;
	
	cin >> n;
	while (cin >> n) {
		v.push_back(n);
	}
	
	sort(v.begin(), v.end());
	
	int distinct = 1;
	for (auto i = 1U; i < v.size(); i++) {
		if (v[i] != v[i-1]) distinct++;
	}
	
	cout << distinct << endl;
}
