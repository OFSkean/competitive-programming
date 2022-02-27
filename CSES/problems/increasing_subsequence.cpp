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

// find  what location key should go in the endings array
int binsearch(int key, int l, int r) {
	while (l <= r) {
		int mid = (l + r) / 2;
		if (key < endings[mid]) r = mid - 1;
		else if (key > endings[mid]) l = mid + 1;
		else return mid;
	}

	return l;
}

// performs DP algorithm
// endings array position i stores minimum ending to i-length increasing subsequence
void solve(int n) {
	int ans = 0;

	REP(i, n) {
		int bestLengthToAppendTo = binsearch(arr[i], 0, ans);
		
		if (arr[i] < endings[bestLengthToAppendTo]) {
			if (bestLengthToAppendTo == ans) {
				endings[ans] = arr[i];
				ans = max(1, ans+1);
			}
			else {
				endings[bestLengthToAppendTo] = arr[i];
			}

		}
	}

	cout << ans << endl;
}

int main() {
	SPEED;
	int n;
	cin >> n;

	// read in vals
	REP(i, n) {
		cin >> arr[i];
	}

	// initialize endings array to INT_MAX
	REP(i, n) {
		endings[i] = INT_MAX;
	}

	solve(n);
}
