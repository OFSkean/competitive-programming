#include <bits/stdc++.h>
using namespace std;

using cd = complex<double>;
const double PI = acos(-1);
#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i,a,b) for(ll i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)

void output_vector(vector<int> v) {
	cout << sz(v) << endl;
	for (auto i: v) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	SPEED;
	string record;
	cin >> record;

	vector<int> result;
	
	FOR(k, 1, sz(record)+1) {
		int alicescore = 0; int bobscore=0;
		int alicewins = 0; int bobwins=0;
		REP(j, sz(record)) {
			if (record[j] == 'A') alicescore++;
			else bobscore++;

			if (alicescore >= k || bobscore >=k) {
				if (alicescore >= k) alicewins++;
				else bobwins++;

				alicescore = 0; bobscore = 0;
			}
		}

		if (alicewins > bobwins) result.pb(k);
	}
	
	output_vector(result);
}
