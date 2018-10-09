// Hal 9000.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char** argv) {
	printf("Hal 9000 is a program that searches for humans to destroy.\nThe position of the human is randomly selected at the start of runtime.\nAnd then binary search is used to find the humans position.\n\n");
	srand(time(NULL)); // reset the seed at runtime.
	int top = 64, bottom = 1, person = (rand() % 64) + 1; // define all of our variables.
	printf("Top of search range = %i\nBottom of search range = %i\n\n", top, bottom);
	int bsPredict = ((top - bottom) / 2) + bottom, bsCount = 0;
	int rndPredict = (rand() % 64) + 1, rndCount = 0;
	int hmPredict = 0, hmCount = 0;
	//while (bsPredict != person || lsPredict != person || rndPredict != person) {
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
		printf("Binary Search AI\nTop of search range = %i\nBottom of search range = %i\nPrediction = ~%i\n", top, bottom, bsPredict);
		if (bsPredict == person) {
			bottom = top;
			printf("Person found at %i, in %i tries.\n", bsPredict, bsCount);
			break;
		}
		else if (bsPredict > person) {
			printf("Prediction too high.\n\n");
			top = --bsPredict;
			//printf("Top of search range = %i\n", top);
		}
		else {
			printf("Prediction too low.\n\n");
			bottom = ++bsPredict;
			//printf("Bottom of search range = %i\n", bottom);
		}
	}
	printf("\n");
	for (int lsPredict = 0; lsPredict < person; lsPredict++) {
		printf("lsPredict = %i\n", lsPredict);
	}
	printf("\n\n");
	do
	{
		rndPredict = (rand() % 64) + 1;
		rndCount++;
		printf("Random Guess #%i = %i\n", rndCount, rndPredict);

	} while (rndPredict != person);
	printf("Random found the person in %i tries\n\n", rndCount);

	system("pause");
	return 0;
}