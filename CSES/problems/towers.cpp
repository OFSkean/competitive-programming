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

    vector<int> towers;
    int q;
    while(cin >> q) {
        bool found = false;
        
        REP(i, towers.size()) {
            if (towers[i] > q) {
                found = true;
                towers[i] = q;
                break;
            }    
        }

        if (!found) {
            towers.pb(q);
        }
    }

    cout << towers.size() << endl;

}
