#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Calculator/Array.h"
#include "../Calculator/Array.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorTest
{		
	TEST_CLASS(ArrayTest)
	{
	public:
		
		TEST_METHOD(Array_DefaultConstructorTest)
		{
			try {
				Array<int> arr;
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::Fail();
			}
		}

		TEST_METHOD(Array_ParameterizedConstructorTest)
		{
			try {
				Array<int> arr(100);
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::Fail();
			}
		}

		TEST_METHOD(Array_BracketAssignmentTest) {
			try {
				Array<int> arr(10);
				int val = 100;
				arr[0] = val;

				Assert::AreEqual(val, arr[0]);
			}
			catch (...) {
				Assert::Fail();
			}
		}

		TEST_METHOD(Array_BracketRetrievalTest) {
			try {
				Array<int> arr(10);
				int val = 100;
				arr[0] = val;

				int item = arr[0];

				Assert::AreEqual(val, item);
			}
			catch (...) {
				Assert::Fail();
			}
		}

		TEST_METHOD(Array_EqualAssignmentOperatorTest) {
			try {
				Array<int> arr(10);
				int val_one = 10;
				int val_two = 20;
				arr[0] = val_one;
				arr[1] = val_two;

				Array<int> arr_two;
				arr_two = arr;

				Assert::AreEqual(val_one, arr_two[0]);
				Assert::AreEqual(val_two, arr_two[1]);
			}
			catch (...) {
				Assert::Fail();
			}
		}

		TEST_METHOD(Array_AddTest) {
			try {
				Array<int> arr;
				int val = 100;
				
				arr.Add(val);

				Assert::AreEqual(1, (int)arr.GetCapacity());
			}
			catch (...) {
				Assert::Fail();
			}
		}

		TEST_METHOD(Array_AddTest_AddsToEnd)
		{
			try {
				Array<int> arr(10);
				int val = 100;
				int cap = arr.GetCapacity();

				arr.Add(val);

				int newCap = arr.GetCapacity();
				int retrieved = arr[newCap - 1];

				Assert::AreEqual(newCap, cap + 1);
				Assert::AreEqual(val, retrieved);
			}
			catch (...) {
				Assert::Fail();
			}
		}

		TEST_METHOD(Array_GetTest)
		{
			try {
				Array<int> arr(10);
				int val_one = 100;
				int val_two = 200;

				arr[0] = val_one;

				int retrieved = arr.Get(0);

				retrieved = val_two;

				Assert::AreEqual(val_two, arr[0]);
			}
			catch (...) {
				Assert::Fail();
			}
		}

	};
}