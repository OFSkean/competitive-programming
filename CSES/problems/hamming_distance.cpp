#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)

const int k = 30;
const int MAXSIZE = 2e4+1;
bitset<k> bitstrings[MAXSIZE] = {0};

int main() {
	SPEED;
	
	int n, kn;
	cin >> n >> kn;
	REP(i, n) {
		string x;
		cin >> bitstrings[i];
	}
	
	int minimum = 1e6;
	REP(i, n) {
		FOR(j, i+1, n) {
			int distance_ij = (bitstrings[i] ^ bitstrings[j]).count();
			minimum = min(minimum, distance_ij);
		}
	}
	
	cout << minimum << endl;
	
}
