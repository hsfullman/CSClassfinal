// Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
	//vector <int> scores;
	int scores[5];
public:
	void input() {
		for (int i = 0; i < 5; i++) {
			cin >> scores[i];
		}
	}
	int calculateTotalScore() {
		int sum = 0;
		for (int i = 0; i < 5; i++) {
			sum += scores[i];
			return sum;
		}
	}

};
int main() {
	int n; // number of students
	cin >> n;
	Student* s = new Student[n]; // an array of n students

	for (int i = 0; i < n; i++) {
		s[i].input();
	}

	// calculate kristen's score
	int kristen_score = s[0].calculateTotalScore();

	// determine how many students scored higher than kristen
	int count = 0;
	for (int i = 1; i < n; i++) {
		int total = s[i].calculateTotalScore();
		if (total > kristen_score) {
			count++;
		}
	}

	// print result
	cout << count;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
