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
	REP (i, n) {
		ll ax, ay, bx, by, px, py;
		cin >> ax >> ay >> bx >> by >> px >> py;
		
		// make A the origin
		bx -= ax;
		px -= ax;
		by -= ay;
		py -= ay;
		
		// take cross product
		ll cross = (bx * py) - (px * by);
		if (cross < 0) cout << "RIGHT" << endl;
		else if (cross > 0) cout << "LEFT" << endl;
		else cout << "TOUCH" << endl; 
		
	}
}
