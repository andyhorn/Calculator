#include "Calculator.h"
#include "Array.cpp"

Calculator::Calculator() {
	
}

Calculator::~Calculator() {

}

Array<int>* Calculator::Primes(int start, int end) {
	Array<int>* results = new Array<int>;
	bool accept;

	for (int num = start; num <= end; num++) {
		accept = true;

		for (int divisor = 2; divisor < num; divisor++) {
			if (num % divisor == 0) {
				accept = false;
				break;
			}
		}

		if (accept) {
			results->Add(num);
		}
	}

	return results;
}

Array<int>* Calculator::SumOfSquares(int start, int end) {
	Array<int>* results = new Array<int>;
	int sum = 0;

	for (int i = start; i <= end; i++) {
		Array<int>* digits = m_get_digits(i);

		for (int j = 0; j < digits->Length(); j++) {
			int val = (*digits)[j];

			sum += val * val;
		}

		if (sum == i) {
			results->Add(i);
		}

		delete digits;
	}

	return results;
}

Array<int>* Calculator::SquareOfSums(int start, int end) {
	Array<int>* results = new Array<int>;
	int sum, square;

	for (int i = start; i <= end; i++) {
		Array<int>* digits = m_get_digits(i);
		sum = 0;
		square = 0;

		for (int j = 0; j < digits->Length(); j++) {
			sum += (*digits)[j];
		}

		square = sum * sum;

		if (square == i) {
			results->Add(i);
		}

		delete digits;
	}

	return results;
}

Array<int>* Calculator::m_get_digits(int num) {
	Array<int>* results = new Array<int>;

	int val = num, quotient, remainder;

	while (val >= 10) {
		remainder = val % 10;
		quotient = val / 10;

		results->Add(remainder);

		val = quotient;
	}

	results->Add(val);

	return results;
}