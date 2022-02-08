#include <bits/stdc++.h>
using namespace std;

void printSign(int day, string month) {
	if ((month == "Mar" && day >= 21) || (month == "Apr" && day <= 20))
		cout << "Aries" << endl;
		
	else if ((month == "Apr"&& day >= 21) || (month == "May" && day <= 20))
		cout << "Taurus" << endl;
		
	else if ((month == "May"&& day >= 21) || (month == "Jun" && day <= 21))
		cout << "Gemini" << endl;
		
	else if ((month == "Jun" &&day >= 22) || (month == "Jul" && day <= 22))
		cout << "Cancer" << endl;
		
	else if ((month == "Jul" &&day >= 23) || (month == "Aug" && day <= 22))
		cout << "Leo" << endl;
		
	else if ((month == "Aug" &&day >= 23) || (month == "Sep" && day <= 21))
		cout << "Virgo" << endl;
		
	else if ((month == "Sep" &&day >= 22) || (month == "Oct" && day <= 22))
		cout << "Libra" << endl;
		
	else if ((month == "Oct" &&day >= 23) || (month == "Nov" && day <= 22))
		cout << "Scorpio" << endl;
		
	else if ((month == "Nov" &&day >= 23) || (month == "Dec" && day <= 21))
		cout << "Sagittarius" << endl;
		
	else if ((month == "Dec" &&day >= 22) || (month == "Jan" && day <= 20))
		cout << "Capricorn" << endl;
		
	else if ((month == "Jan" &&day >= 21) || (month == "Feb" && day <= 19))
		cout << "Aquarius" << endl;
		
	else if ((month == "Feb" &&day >= 20) || (month == "Mar" && day <= 20))
		cout << "Pisces" << endl;
	
}

int main() {
	int numTests;
	string month;
	int day;
	
	cin >> numTests;
	for (int i = 0; i < numTests; i++) {
		cin >> day >> month;
		printSign(day, month);
	}
}
