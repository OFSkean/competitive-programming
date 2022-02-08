#include <bits/stdc++.h>
using namespace std;

int main() {
	int numTests;
	
	cin >> numTests;
	for (int i = 0; i < numTests; i++) {
		int numCities;
		set<string> cities;
		cin >> numCities;
		for (int j =0; j<numCities; j++) {
			string cityName;
			cin >> cityName;
			cities.insert(cityName);
		}
		
		cout << cities.size() << endl;
	}
}

