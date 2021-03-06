// Hal 9000.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char** argv) {
	printf("Hal 9000 is a program that searches for humans to destroy.\nThe position of the human is randomly selected at the start of runtime.\nAnd then binary search is used to find the humans position.\n\n");
	srand(time(NULL)); // reset the seed at runtime.
	int play = 0;
	while (play == 0) {
		int top = 64, bottom = 1, person = (rand() % 64) + 1; // define all of our variables.
		printf("Top of search range = %i\nBottom of search range = %i\n\n", top, bottom);
		int bsPredict = ((top - bottom) / 2) + bottom, bsCount = 0;
		int rndPredict = (rand() % 64) + 1, rndCount = 0;
		int hmPredict = 0, hmCount = 0;
		do
		{
			printf("Enter guess of where the human is:  ");
			cin >> hmPredict;
			hmCount++;
			if (hmPredict == person)
			{
				printf("You found the human at %i, in %i tries\n\n\n", person, hmCount);
			}
		} while (hmPredict != person);
		while (bottom <= top) {
			bsPredict = ((top - bottom) / 2) + bottom;
			bsCount++;
			//printf("Binary Search AI\nTop of search range = %i\nBottom of search range = %i\nPrediction = ~%i\n", top, bottom, bsPredict);
			if (bsPredict == person) {
				bottom = top;
				printf("Bineary Search found the person at %i, in %i tries.\n\n", bsPredict, bsCount);
				break;
			}
			else if (bsPredict > person) {
				top = --bsPredict;
			}
			else {
				bottom = ++bsPredict;
			}
		}
		int lsPredict = 0;
		for (; lsPredict < person; lsPredict++) {}
		printf("Linear Search found the person at %i in %i iterations\n\n", person, lsPredict);
		do
		{
			rndPredict = (rand() % 64) + 1;
			rndCount++;
		} while (rndPredict != person);
		printf("Random found the person in %i tries\n\n", rndCount);
		printf("Would you like to play again? [y/n]: ");
		string answer;
		getline(cin, answer);
		if (answer[0] == 'n' || answer[0] == 'N') play = 1;
	} 
	return 0;
}