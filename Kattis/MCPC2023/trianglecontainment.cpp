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

ll n, postx;
int binsearch(vector<tuple<ll,ll,ll,ll>> &v, int d) {
	int l = 0; 
	int r = v.size() - 1;
	while (l <= r) {
		int mid = l + (r - l)/2;
		if (get<0>(v[mid]) < d) l = mid+1;
		else if (get<0>(v[mid]) > d) r = mid-1;
		else return mid;
	}
	
	return -1;
}

int main() {
	SPEED;
	cin >> n >> postx;
	
	vector<tuple<ll,ll,ll,ll>> treasures;
	REP(i, n) {
		ll v, x, y;
		cin >> x >> y >> v;
		treasures.pb(make_tuple(i, x, y, v));
	}

	
	auto leftAngleSorted = treasures;
	auto rightAngleSorted = treasures;
	
	sort(all(leftAngleSorted), [ ](const tuple<ll,ll,ll,ll> lhs, const tuple<ll,ll,ll,ll> rhs) 
	{
		double lhs_angle = atan2(get<2>(lhs), get<1>(lhs));
		double rhs_angle = atan2(get<2>(rhs), get<1>(rhs));
		return lhs_angle > rhs_angle;
	});

	REP(i, n) {
		auto cur = leftAngleSorted[i];
		cout << get<0>(cur) << " " << get<1>(cur) << " " << get<2>(cur) << " " << get<3>(cur) << endl;
	}
	sort(all(rightAngleSorted), [ ](const tuple<ll,ll,ll,ll> lhs, const tuple<ll,ll,ll,ll> rhs) 
	{
		double lhs_angle = atan2((postx-get<2>(lhs)), get<1>(lhs));
		double rhs_angle = atan2((postx-get<2>(rhs)), get<1>(rhs));
		
		return lhs_angle > rhs_angle;
	});

	REP(i, n) {
		auto cur = rightAngleSorted[i];
		cout << get<0>(cur) << " " << get<1>(cur) << " " << get<2>(cur) << " " << get<3>(cur) << endl;
	}
	vector<ll> results;
	REP(i, n) {
		int leftangleIdx = i;
		int rightangleIdx = binsearch(rightAngleSorted, get<0>(leftAngleSorted[i]));
		
		ll treasurevalue = 0;
		FOR(j, leftangleIdx, rightangleIdx) {
			treasurevalue += get<3>(leftAngleSorted[i]);
		}
		cout << treasurevalue << endl;
	}
	
}
