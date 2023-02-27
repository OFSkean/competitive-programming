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
		
		if(!invert) {
			a[i] /= 2;
			a[i + N/2] /= 2;
		}
		w *= wn;
	}
}

vector<ll> convolve(vector<ll> const &a, vector<ll> const &b) {
	auto N = next_power_of_two(sz(a) + sz(b) - 1);
	vector<cd> fa(all(a)), fb(all(b));
	vector<ll> c(N);

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

void print_vector(vector<ll> const &a) {
		REP(i, sz(a)) {
			cout << a[i] << endl;
		}
}

void print_vector(vector<vector<ll>> const &a) {
		REP(i, sz(a)) {
			REP(j, sz(a[i])) {
				cout << a[i][j];
			}
			cout << endl;
		}
}

void print_vector(vector<cd> const &a) {
		REP(i, sz(a)) {
			cout << a[i] << endl;
		}
		cout << endl;
}
void print_vector(vector<bitset<16>> const &a) {
		REP(i, sz(a)) {
			cout << a[i] << endl;
		}
		cout << endl;
}

vector<cd> to_timedomain(vector<ll> &a) {
	auto N = next_power_of_two(sz(a));
	a.rsz(N);
	vector<cd> fa(all(a));
	
	fft(fa, -1);
	return fa;
}

vector<ll> td_multiply(vector<ll> &a, vector<ll> &b) {
	auto N = next_power_of_two(sz(a)+sz(b)+1);
	vector<cd> fa(all(a)), fb(all(b));
	vector<ll> c(N);

	fa.resize(N);
	fb.resize(N);
	
	fft(fa, -1);
	fft(fb, -1);
	
	REP(i, N) {
		fa[i] *= fb[i];
	}
	fft(fa, 1);
	
    REP(i, N) {
		c[i] = min((double) 1, round(fa[i].real()));
	}
	
	return c;
}

int main() {
	SPEED;
	
	int n;
	cin >> n;
	
	vector<vector<ll>> board_signals(n*n, vector<ll>(n*n,0));
	
	vector<ll> fullsignal;
	vector<ll> fullersignal;
	string fullstring;
	
	// which squares are NOT attacked
	REP(i, n*n) {
		REP(j, n*n) {
			int irow = i / n; int icol = i % n;
			int jrow = j / n; int jcol = j % n;

			bool samerow = irow == jrow;
			bool samecol = icol == jcol;
			bool samediag = abs(irow - jrow) == abs(icol - jcol);

			if (i == j) board_signals[i][j] = 1; //cant attack self
			else if (!samerow && !samecol && !samediag) board_signals[i][j] = 1;
			
			fullstring += board_signals[i][j] + '0';
			fullsignal.pb(board_signals[i][j]);
			fullersignal.pb(board_signals[i][j]);
		}
		REP(j, n*n) fullersignal.pb(0);
	}
	
	vector<ll> copy = fullsignal;


	vector<ll> test = fullsignal;
	REP(i, n-1) {
		test = td_multiply(test, fullersignal);
		
		int counts[n] = {0};
		REP(j, test.size()/(n*n)) {
			int summer =  accumulate(test.begin()+j*n*n, test.begin()+(j+1)*n*n, 0);
			cout << summer << endl;
			counts[summer]++;
		}
	} 
	//vector<vector<cd>> b;
	//REP(i, 16) {
		//b.pb(to_timedomain(a[i]));
		//cout << "VECTOR " << i << endl;
		//print_vector(b[i]);
		
		//if (i >= 1) td_multiply(a[i], a[i]);
	//}
}
