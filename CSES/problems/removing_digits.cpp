#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    int numsteps = 0;
    while (n > 0) {
        numsteps++;
        int bestdigit = 0;
        for(int i = 0; i < 7; i++) {
            bestdigit = max(bestdigit, (n / int(pow(10., i))) % 10);
        }
        
        n -= bestdigit;
    }
    cout << numsteps << endl;
}
