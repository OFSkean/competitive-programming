// https://cses.fi/problemset/task/1069

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 

int main() {
	SPEED;
	string s;
	cin >> s;
	
	int best = 1; int prevLength = 1;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == s[i-1]) {
			prevLength += 1;
		} else {
			prevLength = 1;
		}
		best = max(best, prevLength);
	}
	cout << best << endl;
}
