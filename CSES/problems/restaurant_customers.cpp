// solution to https://cses.fi/problemset/result/3513703/
// uses line sweep. can be improved by using pair<int, +- 1>

#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 

int main() {
	SPEED;
	
	vector<int> a, d;
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int y,z;
		cin >> y >> z;
		a.push_back(y); d.push_back(z);
	}
	
	sort(a.begin(), a.end());
	sort(d.begin(), d.end());
	int p1 = 0, p2 = 0;
	int count = 0; int best = 0;
	int timer = 0;
	while (p1 < n && p2 < n) {
		timer = a[p1];
		p1++; count++;
		
		while (d[p2] <= timer) {
			p2++; count--; 
		}
		
		
		best = max(best, count);
	}
	
	cout << best << endl;
}
