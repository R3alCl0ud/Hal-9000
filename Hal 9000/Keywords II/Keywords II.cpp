#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;


int main()
{
	const int maxguesses = 8;
	// Display Title of program to user
	printf("Welcome to Codebreaker II\n");
	// Ask the recruit to login using thier name
	string pname;
	printf("What is your name: ");
	cin >> pname;
	// Hold the recruit's name in a var, and address them by it throughout the simulation.

	// Display an overview of what Keywords II is to the recruit 
	printf("Basically Hangman, you've just got to guess the passwords.\nThats pretty much it.\n\n\n");
	// Display an directions to the recruit on how to use Keywords

	// Create a collection of 10 words you had wrote down manually
	vector<string> words;
	words.push_back("linux");
	words.push_back("apple");
	words.push_back("arch");
	words.push_back("bridge");
	words.push_back("kernel");
	words.push_back("sanders");
	words.push_back("chicken");
	words.push_back("volital");
	words.push_back("physical");
	words.push_back("outlast");
	// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
	string secretwords[3];
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < 3; i++) {
		secretwords[i] = words.at(rand() % 10);
	}
	string guess;
	vector<char> guessedChars;
	int wrongGuesses;
	int notGuessed;
	for (int i = 0; i < 3; i++) { // run three times, one for each word.
		printf("\n\n\nSimulation #%i\n\n", i + 1);
		wrongGuesses = 0;
		guessedChars.clear();
		string wordGuessedChars(secretwords[i].size(), '_');
		while (wrongGuesses < maxguesses && wordGuessedChars != secretwords[i]) { // While recruit hasn�t made too many incorrect guesses and hasn�t guessed the secret word
			// Tell recruit how many incorrect guesses he or she has left
			printf("You have %i remaining guess(es)\n", maxguesses - wrongGuesses);
			// Show recruit the letters he or she has guessed
			cout << wordGuessedChars << endl;

			do {
				printf("\n\nWhat is your guess: ");
				cin >> guess;
				notGuessed = 0;
				if (guess[0]) {
					//printf("%c\n", guess[0]);
					for (unsigned n = 0; n < guessedChars.size(); n++) {
						if (guess[0] == guessedChars[n]) notGuessed = 1;
					}
				}
				if (notGuessed) printf("You've Already Used That Character\n");
			} while (notGuessed);
			guessedChars.push_back(guess[0]);
			if (secretwords[i].find(guess[0]) != -1) {
				for (int n = 0; n < secretwords[i].size(); n++) {
					if (secretwords[i][n] == guess[0]) wordGuessedChars[n] = guess[0];
				}
			}
			else {
				wrongGuesses++;
			}
		}
		if (wrongGuesses == maxguesses) {
			cout << "You Lose The Word Was " << secretwords[i] << "." << endl;
		}
		else {
			cout << endl << "You Win! You Guessed The Word " << secretwords[i] << " With " << wrongGuesses << " Wrong Guesses." << endl;
		}
	}
}