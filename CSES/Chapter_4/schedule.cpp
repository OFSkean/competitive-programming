#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 

void output_vector(vector<pair<int, int>> v) {
	for (auto i: v) {
		cout << i.first << " " << i.second;
		cout << endl;
	}
}

int maxEvents(vector<pair<int, int>> v) {
	int leftTimeBound = v[0].first;
	int numSelected = 0;
	
	int idx = 0;
	while (idx < v.size()) {
		if (v[idx].first >= leftTimeBound) {
			numSelected++;
			leftTimeBound = v[idx].second;
			//cout << v[idx].first << " " << v[idx].second << endl;
			idx++;
		}
		else {
			idx++;
		}
	}
	
	return numSelected;
}

void handleCase() {
	vector<pair<int, int>> tasks;
	int n;
	cin >> n;
	for (int i =0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		tasks.push_back(make_pair(a,b));
	}
	
	sort(tasks.begin(), tasks.end(), [](auto &a, auto &b) {
		if (a.second < b.second) return true;
		if (a.second >= b.second) return false;
		
		if (a.first < b.first) return true;
		if (a.first > b.first) return false;

		return false;
	});
	
	cout << maxEvents(tasks) << endl;
}

int main() {
	SPEED;
	
	int t;
	cin >> t;
	
	for (int i =0; i< t; i++) handleCase();
}
