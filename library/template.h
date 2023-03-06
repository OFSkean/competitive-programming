#ifndef TEST_H
#define TEST_H


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

typedef struct VoidNoOp {
    void operator()() const { };
    template<typename P1, typename... Params>
    void operator()(P1 p1, Params... parameters) {
        (void)(p1);
        operator()(parameters...);
    }
} NOOP;

template <typename G>
void output_vector(vector<G> v) {
	for (auto i: v) {
		cout << i << " ";
	}
	cout << endl;
}

#endif
