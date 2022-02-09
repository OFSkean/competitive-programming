//solution for https://cses.fi/problemset/submit/1640/

#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 

int binSearch(vector<pair<int,int>> & v, int d) {
	int l = 0; 
	int r = v.size() - 1;
	while (l <= r) {
		int mid = l + (r - l)/2;
		if (v[mid].first < d) l = mid+1;
		else if (v[mid].first > d) r = mid-1;
		else return mid;
	}
	
	return -1;
}

int main() {
	SPEED;
	int n, x;
	vector<pair<int,int>> a;
	cin >> n >> x;
	
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		a.push_back(make_pair(temp,i+1));
	}
	
	sort(a.begin(), a.end());
	
	for (int i = 0; i < n; i++) {
		int desired = x - a[i].first;
		if (desired < a[i].first) {break;}
		
		int idx = binSearch(a, desired);
		
		if (idx != -1) {
			if (idx != i) {
				cout << a[i].second << " " << a[idx].second << endl;
				exit(0);
			}
			else {
				if (idx > 0 && a[idx-1].first == desired) {
					cout << a[i].second << " " << a[idx-1].second << endl;
					exit(0);
				}
				else if (idx < n-1 && a[idx+1].first ==desired) {
					cout << a[i].second << " " << a[idx+1].second << endl;
					exit(0);
				}
			}
		}
	}
	
	cout << "IMPOSSIBLE" << endl;
}
