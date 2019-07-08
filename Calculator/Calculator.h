#pragma once

#include "Array.h"

class Calculator {
private:
	Array<int>* m_get_digits(int num);
public:
	Calculator();
	~Calculator();

	Array<int>* Primes(int start, int end);
	Array<int>* SumOfSquares(int start, int end);
	Array<int>* SquareOfSums(int start, int end);
};