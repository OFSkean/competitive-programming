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

const int MAXN = 200005;
int endings[MAXN] = {0};
int arr[MAXN] = {0};

int binsearch(int key, int l, int r) {
	while (l <= r) {
		int mid = l + (l + r) / 2;
		
		if (key < endings[mid]) l = mid + 1;
		else if (key > endings[mid]) r = mid - 1;
		else return mid;
	}
	
	return r;
}

void solve(int n) {
	REP(i, n) {
			
	}
}

int main() {
	SPEED;
	int n;
	cin >> n;
	
	// read in vals
	REP(i, n) {
		cin >> arr[i];
	}

	// initialize rest of array to INT_MAX
	FOR(i, n, MAXN) {
		arr[i] = INT_MAX;
	}

	solve(n);
}
