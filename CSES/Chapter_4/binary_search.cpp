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

int bin_search(vector<int> &v, int x) {
	int a = 0, b = v.size() - 1;
	
	while (a < b) {
		int mid = (b - a) / 2
		if (v[mid] == x) {
			return mid;
		}
		
		if (x < v[mid]) b = mid - 1;
		else a = mid + 1;
	}
	
	return -1
}

int main() {
	SPEED;
}
