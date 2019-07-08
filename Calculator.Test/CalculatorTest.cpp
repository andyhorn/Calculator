#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Calculator/Calculator.h"
#include "../Calculator/Calculator.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorTest
{

	TEST_CLASS(CalculatorTest)
	{
	public:

		TEST_METHOD(Calculator_DefaultConstructorTest)
		{
			try
			{
				Calculator calc;
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(Calculator_PrimesTest)
		{
			Array<int>* results = nullptr;

			try
			{
				Calculator calc;
				results = calc.Primes(0, 10);

				int length = results->GetCapacity();

				Assert::AreEqual(6, length);
			}
			catch (...)
			{
				Assert::Fail();
			}

			if (results != nullptr) {
				delete results;
			}
		}

		TEST_METHOD(Calculator_SumOfSquaresTest)
		{
			Array<int>* results = nullptr;

			try
			{
				Calculator calc;
				results = calc.SumOfSquares(0, 100);

				int length = results->GetCapacity();

				Assert::AreEqual(2, length);
			}
			catch (...)
			{
				Assert::Fail();
			}

			if (results != nullptr) {
				delete results;
			}
		}

		TEST_METHOD(Calculator_SquareOfSumsTest)
		{
			Array<int>* results = nullptr;

			try
			{
				Calculator calc;
				results = calc.SquareOfSums(0, 100);

				int length = results->GetCapacity();

				Assert::AreEqual(3, length);
			}
			catch (...)
			{
				Assert::Fail();
			}

			if (results != nullptr) {
				delete results;
			}
		}

	};
}