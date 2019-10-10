#include <iostream>
using namespace std;

int main() {
	cout << "Enter size of array : ";
	int N;
	cin >> N;

	int array[1000];

	cout << "Enter numbers of array: ";

	for (int i = 0; i < N; i++) {
		cin >> array[i];
	}


	for (int j = N - 1; j >= 0; j--) {
		cout << array[j];
	}
	return 0;
}
