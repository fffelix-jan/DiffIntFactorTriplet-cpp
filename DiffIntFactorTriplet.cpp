// DiffIntFactorTriplet.cpp : This file contains the 'main' function. Program execution begins and ends there.
// MIT License (see the licence in the repo for details)
// Copyright (c) 2019 Félix An, 
// ported from DiffIntFactorTriplet.py , copyright (c) 2018 Félix An
//
// This script is used to find 3 DIFFERENT positive or negative factors for a given number.
// This is a port of my original Python script, and runs much faster than it.

#include <iostream>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main()
{
	int targetNo;
	cout << "Target Number to find factor triplets? Must be a positive integer -> ";
	cin >> targetNo;
	
	int int1 = targetNo * -1;
	int int2 = targetNo * -1;
	int int3 = targetNo * -1;

	cout << "Starting query for target " + to_string(targetNo) + ", all three factors will be different...\n";

	auto startTime = high_resolution_clock::now();

	while (int3 <= targetNo) {
		if (int1 * int2 * int3 == targetNo && int1 != int2 && int2 != int3 && int1 != int3) {
			cout << to_string(int1) + " * " + to_string(int2) + " * " + to_string(int3) + " = " + to_string(targetNo) + "\n";
		}

		if (int1 > targetNo) {
			int2 = int2 + 1;
			int1 = targetNo * -1;
		}
		else {
			int1 = int1 + 1;
		}

		if (int2 > targetNo) {
			int3 = int3 + 1;
			int2 = targetNo * -1;
		}
	}

	auto endTime = high_resolution_clock::now();
	auto totalTime = duration_cast<nanoseconds>(endTime - startTime);
	cout << "Elapsed time: approximately " + to_string(totalTime.count() / 1000000000.0) + " seconds\n";
	cout << "*** FINISHED ***\n";
	
	return 0;
}