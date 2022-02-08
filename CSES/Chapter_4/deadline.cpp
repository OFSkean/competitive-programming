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
	vector<pair<int,int>> tasks;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int a,b;
		cin >> a >> b;
		tasks.push_back(make_pair(a,b));
	}
	
	sort(tasks.begin(), tasks.end(), [](auto& a, auto& b) {
		return a.first < b.first;
	});
	
	int currentTime = 0;
	int cost = 0;
	for (int i =0; i < n; i++) {
		currentTime += tasks[i].first;
		cost += tasks[i].second - currentTime;
	}
	cout << cost << endl;
	
}
