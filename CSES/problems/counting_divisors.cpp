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

const int MAXN = 1e5;
const int MAXVAL = 1e6+5;

int arr[MAXVAL] = {0};

void construct() {
    FOR(i, 2, MAXVAL) {
        for (int j = i; j < MAXVAL; j += i) {
            arr[j]++;
        }
    }
}

int main() {
	SPEED;
    construct();

    int n;
    cin >> n;
    while (cin >> n) {
        cout << arr[n]+1 << endl;
    }
}
