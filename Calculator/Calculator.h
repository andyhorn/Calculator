#pragma once

#include "Array.h"

class Calculator {
private:
	Array<int>* m_int_array;
	Array<double>* m_double_array;
public:
	Calculator();
	~Calculator();

	Primes();
	SumOfSquares();
	SquareOfSums();
};