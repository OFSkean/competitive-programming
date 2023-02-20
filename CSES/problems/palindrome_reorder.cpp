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

int counts[26] = {0};

int main() {
    SPEED;
    string s;
    cin >> s;

    for (auto c : s) {
        counts[c - 'A'] += 1;
    }

    int numOdds = 0;
    int oddIdx = 0;
    REP(i, 26) {
        if (counts[i] % 2) {
            numOdds += 1;
            oddIdx = i;
        }
    }

    if (numOdds > 1) {
        cout << "NO SOLUTION" << endl;
        exit(0);
    }

    string ans = "";

    REP(i, 26) {
        REP(j, counts[i]/2) {
            ans += i + 'A';
        }
    }

    if (!numOdds) {
        cout << ans << string(ans.rbegin(), ans.rend()) << endl;
    }
    else {
        cout << ans << (char)(oddIdx + 'A') << string(ans.rbegin(), ans.rend()) << endl;
    }

}
