// https://cses.fi/problemset/task/1070

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 

int main() {
	SPEED;
	int n;
	cin >> n;
	
	if (n==2 || n == 3) {
		cout << "NO SOLUTION" << endl; 
		exit(0);
	}
	
	for (int i = 2; i < n+1; i+=2) {
		cout << i << " ";
	}
	
	for (int i = 1; i < n+1; i+=2) {
		cout << i << " ";
	}
	

}
