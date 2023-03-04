#include "template.h"
#include "fft.h"

const ll MAXSIZE = 1 << 16;

int main() {
	SPEED;
	ll n, m;
	vector<ll> a, b;
		
	cin >> n >> m;
	
	REP(i, n) {
		ll q;
		cin >> q;
		a.pb(q);
	}
	REP(i, m) {
		ll q;
		cin >> q;
		b.pb(q);
	}
	reverse(all(b));
	
    FFT f;
	vector<ll> c = f.convolve(a, b);
	
	REP(i, sz(a) + sz(b) - 1) {
		cout << c[i] << " ";
	}
	cout << endl;
}
