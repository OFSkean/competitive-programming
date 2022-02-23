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

void output_vector(vector<int> v) {
	for (auto i: v) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	SPEED;
    int n;
    cin >> n;

    int total = n*(n+1) / 2;
    if (total % 2) {
        cout << "NO" << endl;
        exit(0);
    }

    cout << "YES" << endl;
    
    // use gaussian sum trick
    // sum(1..8) = 1 + 2 + 3 + 4
    //           + 8 + 7 + 6 + 5
    // column sums are the same
    //

    int offset = (n%2) ? 1 : 0;
    vector<int> l1;
    vector<int> l2;
    REP(i, n/2) {
        vector<int>* alt = (i % 2) ? &l2 : &l1;

        (*alt).pb(i+1);
        (*alt).pb(n-i-offset);
        
    }
    
    if (n % 2) l2.pb(n);

    cout << l1.size() << endl;
    output_vector(l1);    

    cout << l2.size() << endl;
    output_vector(l2);   
} 
