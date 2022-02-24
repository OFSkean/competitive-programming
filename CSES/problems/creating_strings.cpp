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
    string s;
    cin >> s;
    sort(s.begin(), s.end());

    set<string> perms;

    do {
        perms.insert(s);
    } while (next_permutation(s.begin(), s.end()));
    
    cout << perms.size() << endl;
    for (auto i : perms) {
        cout << i << endl;
    }
}
