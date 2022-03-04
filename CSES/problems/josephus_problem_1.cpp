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

int josephus(int n, int k) {
    int res = 0;
    FOR(i, 1, n+1) {
        res = (res + k) % i;
        cout << res << " ";
    }
    return res+1;
}
int main() {
	SPEED;
    int n;
    cin >> n;
    cout << josephus(n, 2) << endl;
}
