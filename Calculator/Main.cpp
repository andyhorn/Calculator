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
#include "Timer.h"

const Time DEFAULT_UNIT = Time::MS;

void printGui();
void printError(const char* str);
bool getRange(int& begin, int& end);
void printArray(Array<int>* arr);
void printTime(int time, Time unit);

int main() {

	bool run = true;
	Array<int>* arr = nullptr;
	Buffer buf;
	Calculator calc;
	Timer timer;

	while (run)
	{
		printGui();
		std::cout << "Selection: ";
		buf.ReadLine();

		if (buf.IsNumber())
		{
			int selection = std::atoi(buf.GetBuffer()),
				begin = 0,
				end = 0,
				time = 0;

			switch (selection)
			{
			case 0:
				if (getRange(begin, end)) {
					timer.Start();
					arr = calc.Primes(begin, end);
					time = timer.Ms();
				}
				break;
			case 1:
				if (getRange(begin, end)) {
					timer.Start();
					arr = calc.SumOfSquares(begin, end);
					time = timer.Ms();
				}
				break;
			case 2:
				if (getRange(begin, end)) {
					timer.Start();
					arr = calc.SquareOfSums(begin, end);
					time = timer.Ms();
				}
				break;
			default:
				printError("Invalid selection");
				continue;
			}

			printArray(arr);
			printTime(time, DEFAULT_UNIT);
			delete arr;
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

void printTime(int time, Time unit) {

	const char* unit_string;

	std::cout << "Elapsed time: " << time << " ";

	switch (unit) {
	case Time::H:
		unit_string = "hours";
		break;
	case Time::M:
		unit_string = "minutes";
		break;
	case Time::S:
		unit_string = "seconds";
		break;
	case Time::MS:
		unit_string = "milliseconds";
		break;
	}

	std::cout << unit_string << std::endl;
}