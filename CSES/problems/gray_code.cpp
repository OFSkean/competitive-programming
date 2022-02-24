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

vector<string> construct(int n) {
    vector<string> vec;
    
    //base case
    if (n == 1) {
        vec.pb("1");
        vec.pb("0");
        return vec;
    }
    
    // recusive reflection algorithm
    //
    vector<string> prev = construct(n-1);
    for (auto it = prev.begin(); it != prev.end(); it++) {
        vec.pb("0" + *it);
    }

    for (auto it = prev.rbegin(); it != prev.rend(); it++) {
        vec.pb("1" + *it);
    }

    return vec; 
 
}
int main() {
	SPEED;
    int n;
    cin >> n;

    vector<string> res = construct(n);
    REP(i, res.size()) {
        cout << res[i] << endl;
    }
}
