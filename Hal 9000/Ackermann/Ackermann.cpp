// Ackermann.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

uint64_t ackermann(uint64_t m, uint64_t n) {
	if (m == 0) return n + 1;
	if (n == 0) return ackermann(m - 1, 1);
	return ackermann(m - 1, ackermann(m, n - 1));
}

int main()
{
	for (int i = 0; i <= 4; i++) {
		for (int n = 0; n <= 16; n++) {
			printf("Ackermann(%i, %i) = %i\n", i, n, ackermann(i, n));
		}
	}
	return 0;
}