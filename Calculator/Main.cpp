/*
	Author:		Andrew Horn
	Date:		6/3/2019
	File:		Main.cpp
	Overview:	Built to practice with C++ and challenge myself to make large calculations,
				this is a console calculator app that will perform many operations that are
				beyond the capabilities of a typical calculator.
*/

#include <iostream>

void printGui();

int main() {
	printGui();
	return 0;
}

void printGui() {
	std::cout << "[0] Primes" << std::endl;
	std::cout << "[1] Sum of Squares" << std::endl;
	std::cout << "[2] Square of Sums" << std::endl;
}