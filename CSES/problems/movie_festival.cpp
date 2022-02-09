//solution for https://cses.fi/problemset/task/1629

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 

int main() {
	SPEED;
	int n;
	cin >> n;
	vector<pair<int,int>> movies(n);
	
	for (int i = 0; i < n; i++) {
		cin >> movies[i].second >> movies[i].first;
	}
	
	sort(movies.begin(), movies.end());
	
	int count = 0;
	int end = 0;
	
	for (auto movie : movies) {
		if (movie.second >= end) {
			end = movie.first;
			count++;
		}
	}
	
	cout << count << endl;
}
