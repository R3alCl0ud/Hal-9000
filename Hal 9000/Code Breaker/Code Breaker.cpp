// Code Breaker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 10;
	const string WORDS[NUM_WORDS][NUM_FIELDS] = {
		{"wall", "Do you feel you're banging your head against something?"},
		{"glasses", "These might help you see the answer."},
		{"labored", "Going slowly, is it?"},
		{"persistent", "Keep at it."},
		{"jumble", "It's what the game is all about."},
		{"ruby", "Red, black, and the name of a stone."},
		{"blackhat", "Evil computer people."},
		{"linux","Open source kernel."},
		{"arch","The best OS ever."},
		{"ubuntu","Worst OS Distro ever."}
	};
	int keys[] = { 0,0,0 };
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < 3; i++) {
		keys[i] = (rand() % NUM_WORDS);
	}
	cout << "\t\t\tWelcome to the CIA Training Code Breaker!\n\n";
	cout << "Unscramble the letters to find the keyword.\n";
	cout << "Enter 'hint' for a hint.\n";
	cout << "Enter 'quit' to quit the game.\n\n";
	int replay = 1;
	do {
		for (int i = 0; i < 3; i++) {
			string theWord = WORDS[keys[i]][WORD];  // word to guess
			string theHint = WORDS[keys[i]][HINT];  // hint for word

			string jumble = theWord;  // jumbled version of word
			int length = jumble.size();
			for (int n = 0; n < length; ++n) {
				int index1 = (rand() % length);
				int index2 = (rand() % length);
				char temp = jumble[index1];
				jumble[index1] = jumble[index2];
				jumble[index2] = temp;
			}

			cout << "The jumble is: " << jumble;

			string guess;
			cout << "\n\nYour guess: ";
			cin >> guess;

			while ((guess != theWord) && (guess != "quit")) {
				if (guess == "hint") {
					cout << theHint;
				}
				else {
					cout << "Sorry, that's not it.";
				}

				cout << "\n\nYour guess: ";
				cin >> guess;
			}

			if (guess == theWord) {
				cout << "\nThat's it!  You guessed it!\n";
				printf("%i\n", i);
				if (i == 2) {
					printf("Would you like to play again? (Enter \"quit\" to quit)\n");
					cin >> guess;
					if (guess == "quit") { replay = 0; }
				}
			}
			if (guess == "quit") {
				replay = 0;
				break;
			}
		}
	} while (replay == 1);
	cout << "\nThanks for playing.\n";
	return 0;
}