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

const int MAXN = 2e5;
int arr[MAXN+1] = {0};

int main() {
	SPEED;
    int n;
    cin >> n;
    REP(i, n) {
        cin >> arr[i];
    }

    map<int, int> pos;
    int best = 0; int bottom = 0;
    REP(i, n) {
        if (pos.find(arr[i]) == pos.end()) {
            pos[arr[i]]++;
            pos.insert(make_pair(arr[i],i));
        }
        else {
            bottom = s[arr[i]] + 1;
            s[arr[i]] = i;
        }
        
        cout << best << " " << bottom << endl;
        best = max(best, i - bottom + 1);
    }

    cout << best << endl;
}
