// Paper Sissors Rock game in C++ by DrAymeinstein
// 5/12/2023

#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

int generateRandomNumber() { // for the computer
	srand(static_cast<unsigned int>(time(nullptr)));

	int randomNumber = (rand() % 3) + 1;

	return randomNumber;
}

int psr(int c) {
	// Paper   1
	// Sissors 2
	// Rock    3
	int comp_choice = generateRandomNumber();

	if (c == 0) {
		c = 3; // all input c should be between 1 and 3, c€[1, 2, 3]
	}

	string choice;

	switch (c) {
	case 1:
		choice = "Paper";
		break;
	case 2:
		choice = "Sissors";
		break;
	case 3:
		choice = "Rock";
		break;
	}

	string choice_;

	switch (comp_choice) {
	case 1:
		choice_ = "Paper";
		break;
	case 2:
		choice_ = "Sissors";
		break;
	case 3:
		choice_ = "Rock";
		break;
	}

	cout << "You chose:         \t" << c << " - " << choice << endl;
	cout << "The computer chose:\t" << comp_choice << " - " << choice_ << endl;
	cout << "Verdict : \t\t";

	// Possibilities of game
	if (comp_choice == c) {
		cout << "draw" << endl;
	} if (c == (comp_choice + 1) % 3) {
		cout << "win!" << endl;
	} if (c == (comp_choice - 1) % 3) {
		cout << "noob" << endl;
	}
	cout << "\n";

	return 0;
}

int main() {
	cout << "Chose between (1, 2, 3): " << endl;
	cout << "1. Paper   " << endl;
	cout << "2. Sissors " << endl;
	cout << "3. Rock    " << endl;

	int k;
	cin >> k;
	int c;
	if (k > 3 || k <= 0) {
		c = k % 3 + 1; // if the user chose a number other than (1,2,3) it will be computed as (k % 3) + 1
	}
	else {
		c = k;
	}

	psr(c);

	string r;
	cout << "Replay? (Yes/Oui/1 ou No/Non/0): \n ==> ";
	cin >> r;

	if (r == "Oui" || r == "Yes" || r == "1") {
		main();
	}
	else {
		return 0;
	}
}
