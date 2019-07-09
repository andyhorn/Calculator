/*
	Author:		Andrew Horn
	Date:		6/3/2019
	File:		Main.cpp
	Overview:	Built to practice with C++ and challenge myself to make large calculations,
				this is a console calculator app that will perform many operations that are
				beyond the capabilities of a typical calculator.
*/

#include <iostream>
#include "Array.h"
#include "Calculator.h"
#include "Buffer.h"

void printGui();
void printError(const char* str);
bool getRange(int& begin, int& end);
void printArray(Array<int>* arr);

int main() {

	bool run = true;
	Array<int>* arr = nullptr;
	Buffer buf;
	Calculator calc;

	while (run)
	{
		printGui();
		std::cout << "Selection: ";
		buf.ReadLine();

		if (buf.IsNumber())
		{
			int selection = std::atoi(buf.GetBuffer()),
				begin = 0,
				end = 0;

			switch (selection)
			{
			case 0:
				if (getRange(begin, end)) {
					arr = calc.Primes(begin, end);
					printArray(arr);
					delete arr;
				}
				break;
			case 1:
				if (getRange(begin, end)) {
					arr = calc.SumOfSquares(begin, end);
					printArray(arr);
					delete arr;
				}
				break;
			case 2:
				if (getRange(begin, end)) {
					arr = calc.SquareOfSums(begin, end);
					printArray(arr);
					delete arr;
				}
				break;
			default:
				printError("Invalid selection");
				break;
			}
		}
		else
		{
			char character = buf.GetBuffer()[0];
			if (character == 'q')
			{
				run = false;
			}
			else
			{
				printError("Invalid selection");
			}
		}
	}
	return 0;
}

void printGui() {
	std::cout << "[0] Primes" << std::endl;
	std::cout << "[1] Sum of Squares" << std::endl;
	std::cout << "[2] Square of Sums" << std::endl;
	std::cout << "[q] Quit" << std::endl;
}

void printError(const char* str) {
	std::cout << "Error: " << str << std::endl;
}

bool getRange(int& begin, int& end) {
	Buffer buf;
	std::cout << "Range begin: ";
	buf.ReadLine();

	if (buf.IsNumber()) {
		begin = std::atoi(buf.GetBuffer());
	}
	else {
		printError("Please enter a valid integer");
		return false;
	}

	std::cout << "Range end: ";
	buf.ReadLine();

	if (buf.IsNumber()) {
		end = std::atoi(buf.GetBuffer());
	}
	else {
		printError("Please enter a valid integer");
		return false;
	}

	return true;
}

void printArray(Array<int>* arr) {
	std::cout << "\nResults:" << std::endl;
	std::cout << "[";

	int len = arr->Length();

	for (int i = 0; i < len - 1; i++) {
		std::cout << (*arr)[i] << ", ";
	}

	std::cout << (*arr)[len - 1] << "]\n" << std::endl;
}