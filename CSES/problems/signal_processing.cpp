#include <bits/stdc++.h>
using namespace std;

#define ll long long
using cd = complex<double>;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0) 
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)
const double PI = acos(-1);

const ll MAXSIZE = 1 << 16;

int next_power_of_two(int n) {
    int i = 0;
    for (--n; n > 0; n >>= 1) {
        i++;
    }
    return 1 << i;
}

void fft(vector<cd> &a, bool invert) {
	ll N = sz(a);
	
	if (N == 1) return;
	
	vector<cd> a_even(N/2), a_odd(N/2);
	for (int i = 0; 2 * i < N; i++) {
		a_even[i] = a[2*i];
		a_odd[i]  = a[2*i + 1];
	}
	fft(a_even, invert);
	fft(a_odd, invert);
	
	double angle = (invert ? -1 : 1) * (2*PI / N);
	cd w(1), wn(cos(angle), sin(angle));
	for (int i = 0; 2 * i < N; i++) {
		a[i] = a_even[i] + w*a_odd[i];
		a[i + N/2] = a_even[i] - w*a_odd[i];
		
		if(invert) {
			a[i] /= 2;
			a[i + N/2] /= 2;
		}
		w *= wn;
	}
}

vector<int> convolve(vector<int> const &a, vector<int> const &b) {
	auto N = next_power_of_two(sz(a) + sz(b) - 1);
	vector<cd> fa(all(a)), fb(all(b));
	vector<int> c(N);

	fa.resize(N);
	fb.resize(N);

	fft(fa, 0);
	fft(fb, 0);
	REP(i, N) {
		fa[i] *= fb[i];
	}
	fft(fa, 1);
	
    REP(i, N) {
		c[i] = round(fa[i].real());
	}
	
	return c;
}

int main() {
	SPEED;
	ll n, m;
	vector<int> a, b;
	
	
	cin >> n >> m;
	
	REP(i, n) {
		int q;
		cin >> q;
		a.pb(q);
	}
	REP(i, m) {
		int q;
		cin >> q;
		b.pb(q);
	}
	reverse(all(b));
	
	vector<int> c = convolve(a, b);
	
	REP(i, sz(a) + sz(b) - 1) {
		cout << c[i] << " ";
	}
	cout << endl;
}
