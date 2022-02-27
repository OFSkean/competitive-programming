// solution to https://cses.fi/problemset/result/3513703/
// uses line sweep. can be improved by using pair<int, +- 1>

#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 

int main() {
	SPEED;
	
	vector<pair<int, int>> events;
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int y,z;
		cin >> y >> z;
		events.push_back(make_pair(y, 1));
		events.push_back(make_pair(z, -1));
	}
	
	sort(events.begin(), events.end());
	
	int best = 0; int count = 0;
	for (pair<int,int> event : events) {
		count += event.second;
		best = max(best, count);
	}
	
	cout << best << endl;
}
