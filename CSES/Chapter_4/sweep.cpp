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
	vector<int> events;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a ,b;
		cin >> a >> b;
		events.push_back(a);
		events.push_back(-b);
	}
	
	sort(events.begin(), events.end(), [](auto &a, auto &b) {
		return abs(a) < abs(b);
	});
	
	int best, sum = 0;
	for (auto i : events) {
		if (i < 0) {
			sum--;
		} else sum++;
		
		best=max(sum, best);
	}
	
	cout << best << endl;
	
	
	
	
}
