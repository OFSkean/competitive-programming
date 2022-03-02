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

const int MAXVAL = 1e6+1;
int occ[MAXVAL] = {0};

int main() {
	SPEED;
    int n;
    cin >> n;

    REP(i, n) {
        int x;
        cin >> x;
        occ[x]++;
    }

    for (int i = MAXVAL; i > 0; i--) {
        int count = 0;
        for (int j = i; j <= MAXVAL; j+=i) {
            count += occ[j];
        }

        if (count > 1) {
            cout << i << endl;
            break;
        }
    }
}
