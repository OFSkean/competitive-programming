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
	for (auto i: v) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	SPEED;
	
	int n, m;
	cin >> n >> m;
	
    // key-> value : number->index of appearance
	vector<int> nums_to_pos(n+1);
    vector<int> pos_to_nums(n+1);
	REP(i, n) {
		int q;
		cin >> q;
		nums_to_pos[q] = i;
        pos_to_nums[i] = q;
	}
	
    // initialize inversion-tracking array
    // solution to collection_numbers.cpp is the sum of this array
    vector<bool> inversions(n+1);
	FOR(i, 2, n+1) {
		if (nums_to_pos[i-1] > nums_to_pos[i]) inversions[i] = true;
	}

    int summation = 1 + accumulate(all(inversions), 0);
    cout << summation << endl;
    REP(i, m) {
        int a, b;
        cin >> a >> b;
        
        int diff_before = (nums_to_pos[pos_to_nums[a]-1] > nums_to_pos[pos_to_nums[a]]) + (nums_to_pos[pos_to_nums[a]] > nums_to_pos[pos_to_nums[a]+1]) +  (nums_to_pos[pos_to_nums[b]-1] > nums_to_pos[pos_to_nums[b]]) + (nums_to_pos[pos_to_nums[b]] > nums_to_pos[pos_to_nums[b]+1]);
        
        output_vector(nums_to_pos);
        swap(nums_to_pos[pos_to_nums[a]], nums_to_pos[pos_to_nums[b]]);
        output_vector(nums_to_pos);
        
        output_vector(pos_to_nums);
        swap(pos_to_nums[a], pos_to_nums[b]);
        output_vector(pos_to_nums);

        int diff_after = (nums_to_pos[pos_to_nums[a]-1] > nums_to_pos[pos_to_nums[a]]) + (nums_to_pos[pos_to_nums[a]] > nums_to_pos[pos_to_nums[a]+1]) +  (nums_to_pos[pos_to_nums[b]-1] > nums_to_pos[pos_to_nums[b]]) + (nums_to_pos[pos_to_nums[b]] > nums_to_pos[pos_to_nums[b]+1]);
        
        summation += (diff_after - diff_before); 
        cout << summation << endl;
    }
	
}
