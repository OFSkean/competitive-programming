// Solution for https://cses.fi/problemset/task/1068

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 

int main() {
	SPEED;
	ll n;
	cin >> n;
	
	while (n > 1) {
		cout << n << " ";
		if (!(n % 2)) n /=2;
		else n=3*n+1;
	}
	
	cout << n << endl;
}
