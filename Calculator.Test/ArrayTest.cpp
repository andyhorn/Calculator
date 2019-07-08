#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Calculator/Array.h"
#include "../Calculator/Array.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorTest
{
	struct TestStruct
	{
		int integer;
		char* text;
	};

	TEST_CLASS(ArrayTest)
	{
	public:

		TEST_METHOD(Array_DefaultConstructorTest)
		{
			try
			{
				Array<int> arr;
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(Array_ParameterizedConstructorTest)
		{
			try
			{
				Array<int> arr(100);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(Array_BracketAssignmentTest)
		{
			try
			{
				Array<int> arr(10);
				int val = 100;
				arr[0] = val;

				Assert::AreEqual(val, arr[0]);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(Array_BracketAssignmentStructTest)
		{
			try
			{
				Array<TestStruct> arr(10);
				TestStruct s;
				s.integer = 100;
				s.text = "unchanged";

				arr[0] = s;

				int intVal = arr[0].integer;
				char* textVal = arr[0].text;

				Assert::AreEqual(s.integer, intVal);
				Assert::AreEqual(s.text, textVal);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(Array_BracketModificationTest)
		{
			const int originalInt = 100;
			const int newInt = 200;
			char* originalText = "unchanged";
			char* newText = "changed";

			try
			{
				Array<TestStruct> arr(10);
				TestStruct s;
				s.integer = originalInt;
				s.text = originalText;

				arr[0] = s;

				arr[0].integer = newInt;
				arr[0].text = newText;

				Assert::AreEqual(newText, arr[0].text);
				Assert::AreEqual(newInt, arr[0].integer);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(Array_BracketRetrievalTest)
		{
			try
			{
				Array<int> arr(10);
				int val = 100;
				arr[0] = val;

				int item = arr[0];

				Assert::AreEqual(val, item);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(Array_GetRetrievalTest)
		{
			try
			{
				Array<int> arr;
				//int val = 10;
				//arr.Add(val);
				arr.Add(10);

				int val = arr[0];

				Assert::AreEqual(10, val);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(Array_GetModificationTest)
		{
			try
			{
				Array<TestStruct> arr;
				TestStruct s;
				s.integer = 100;
				s.text = "original";

				arr.Add(s);

				arr.Get(0).integer = 200;
				arr.Get(0).text = "new";

				Assert::AreEqual(200, arr[0].integer);
				Assert::AreEqual("new", arr[0].text);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(Array_EqualAssignmentOperatorTest)
		{
			try
			{
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
			catch (...)
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(Array_AddTest)
		{
			try
			{
				Array<int> arr;
				int val = 100;

				arr.Add(val);

				Assert::AreEqual(1, (int)arr.Length());
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(Array_AddTest_AddsToEnd)
		{
			try
			{
				Array<int> arr(10);
				int val = 100;
				int cap = arr.Length();

				arr.Add(val);

				int newCap = arr.Length();
				int retrieved = arr[newCap - 1];

				Assert::AreEqual(newCap, cap + 1);
				Assert::AreEqual(val, retrieved);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(Array_GetTest)
		{
			try
			{
				Array<int> arr(10);
				int val = 100;
				int index = 0;
				arr[index] = val;

				int retrieved = arr.Get(index);

				Assert::AreEqual(val, retrieved);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(Array_PutTest)
		{
			try
			{
				Array<int> arr(10);
				int val = 100;
				int index = 0;

				arr.Put(val, index);

				int retrieved = arr[index];

				Assert::AreEqual(val, retrieved);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

		//TEST_METHOD(Array_RemoveTest) {
		//	try {
		//		int capacity = 10;
		//		Array<int> arr(capacity);

		//		for (int i = 0; i < capacity; i++)
		//		{
		//			arr[i] = i;
		//		}

		//		arr.Remove(9);

		//		Assert::AreNotEqual(9, arr[9]);
		//	}
		//	catch (...) {
		//		Assert::Fail();
		//	}
		//}

		TEST_METHOD(Array_GetCapacityTest)
		{
			int capacity = 10;
			Array<int> arr(capacity);

			Assert::AreEqual(capacity, (int)arr.Length());
		}

	};
}