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

int main() {
	SPEED;
    int n;
    cin >> n;
    REP(i, n) {
        ll x,y;
        cin >> y >> x;
        ll ans = 0;
        if (!(y % 2) && x <= y)
            ans = y*y - (x-1);
        else if ((x % 2) && y < x)
            ans = x*x  - (y-1);
        else if (!(x % 2) && y <= x)
            ans = x*x - 2*(x-1) + (y -1);
        else
            ans = y*y - 2*(y-1) + x-1;

        cout << ans << endl;
    }


}
