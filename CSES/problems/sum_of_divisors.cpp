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

const int MOD = 1e9 + 7;

int main() {
	SPEED;
    ll n;
    cin >> n;
    
    if (n == 1) {
        cout << 1 << endl;
        exit(0);
    }

    ll sigma = 0;
    ll i = 0;
    do {
        i++;
        sigma += i*(n / i);
        sigma %= MOD;
    } while (i*i <= n);
    
    if (n % 2 == 0 && n/2 > i) sigma = (sigma + (n/2)) % MOD;
   
    // sum rest of numbers
    sigma += (n*(n+1)/2) - ((i)*(i+1)/2);
    sigma %= MOD; 
    cout << sigma << endl;
}
