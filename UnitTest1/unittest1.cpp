#include "stdafx.h"
#include "CppUnitTest.h"
#include "../templList.h"
#include "../boxwood.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(pushBackTest)
	{
	public:
		TEST_METHOD(pushBackInteger_oneElementWithTrueStatement)
		{
			myList <int> list;

			list.push_back(9);
			Assert::IsTrue((list.get_size() == 1) && !(list.isEmpty()) && (list.at(0) == 9));
		}

		TEST_METHOD(pushBackDouble_threeElementsCheckingSizeAndPositions)
		{
			myList <double> list;

			list.push_back(2.2);
			list.push_back(3.3);
			list.push_back(1.1);
			Assert::IsTrue((list.get_size() == 3) && (list.at(0) == 2.2) && (list.at(1) == 3.3) && (list.at(2) == 1.1));
		}

		TEST_METHOD(pushBackBoxwood_twoElementsWithFalseStatement)
		{
			myList <boxwood> list;
			boxwood bw;

			bw.age = 2;
			bw.height = 7.7;
			list.push_back(bw);
			Assert::IsFalse((list.get_size() == 1) && (list.at(0).age == 1) && (list.at(0).height == 7.7));
		}
	};

	TEST_CLASS(pushFrontTest)
	{
	public:
		TEST_METHOD(pushFrontInteger_threeElementsCheckingSizeAndPositions)
		{
			myList <int> list;

			list.push_front(2);
			list.push_front(3);
			list.push_front(1);
			Assert::IsTrue((list.get_size() == 3) && (list.at(0) == 1) && (list.at(1) == 3) && (list.at(2) == 2));
		}

		TEST_METHOD(pushFrontDouble_oneElementWithTrueStatement)
		{
			myList <double> list;

			list.push_front(9.99);
			Assert::IsTrue((list.get_size() == 1) && !(list.isEmpty()) && (list.at(0) == 9.99));
		}

		TEST_METHOD(pushFrontBoxwood_threeElementsCheckingPositionsAndValues)
		{
			myList <boxwood> list;
			boxwood bw;

			bw.age = 100;
			bw.height = 8.75;
			list.push_front(bw);

			bw.age = 70;
			bw.height = 5.67;
			list.push_front(bw);

			bw.age = 0;
			bw.height = 3.18;
			list.push_front(bw);

			Assert::IsFalse((list.at(0).age == 100) && (list.at(0).height == 8.75));
			Assert::IsTrue((list.at(1).age == 70) && (list.at(1).height == 5.67));
			Assert::IsFalse((list.at(2).age == 0) && (list.at(2).height == 3.18));
		}
	};

	TEST_CLASS(popBackTest)
	{
	public:
		TEST_METHOD(popBackInteger_oneElementCheckingEmptynessAfterPoppingBack)
		{
			myList <int> list;

			list.push_back(9);
			list.pop_back();
			Assert::IsTrue(list.isEmpty());
		}

		TEST_METHOD(popBackDouble_twoElementCheckingRestOneParameters)
		{
			myList <double> list;

			list.push_back(-9.99);
			list.push_back(10.1);
			list.pop_back();
			Assert::IsTrue(!(list.isEmpty()) && (list.at(0) == -9.99) && (list.get_size() == 1));

			list.pop_back();
			Assert::IsTrue((list.isEmpty()) && (list.get_size() == 0));
		}

		TEST_METHOD(popBackBoxwood_oneElementWithFalseSizeStatement)
		{
			myList <boxwood> list;
			boxwood bw;

			bw.age = 12;
			bw.height = 7.09;
			list.push_back(bw);
			list.pop_back();

			Assert::IsFalse(list.get_size() == 1);
		}
	};

	TEST_CLASS(popFrontTest)
	{
	public:
		TEST_METHOD(popFrontInteger_oneElementCheckingEmptynessAfterPoppingFront)
		{
			myList <int> list;

			list.push_back(9);
			list.pop_front();
			Assert::IsTrue(list.isEmpty());
		}

		TEST_METHOD(popFrontDouble_twoElementCheckingRestOneParametersAndEmptynessAfterPoppingFrontLast)
		{
			myList <double> list;

			list.push_back(9.87);
			list.push_back(10.01);
			list.pop_front();
			Assert::IsTrue(!(list.isEmpty()) && (list.at(0) == 10.01) && (list.get_size() == 1));

			list.pop_back();
			Assert::IsTrue((list.isEmpty()) && (list.get_size() == 0));
		}

		TEST_METHOD(popFrontBoxwood_oneElementAndPoppingEmptyList)
		{
			myList <boxwood> list;
			boxwood bw;

			bw.age = 9;
			bw.height = 0.33;
			list.push_back(bw);
			list.pop_front();
			list.pop_front();
			Assert::IsFalse((list.get_size()) == 1);
		}
	};

	TEST_CLASS(insertTest)
	{
	public:
		TEST_METHOD(insertInteger_inTheBeginningAndInTheEnd)
		{
			myList <int> list;

			list.push_back(9);
			list.insert(0, -1);
			Assert::IsTrue((!(list.isEmpty())) && (list.at(0) == -1) && (list.get_size() == 2));
			list.insert(2, 2);
			Assert::IsTrue((!(list.isEmpty())) && (list.at(2) == 2) && (list.get_size() == 3));
		}

		TEST_METHOD(insertDouble_inTheMiddle)
		{
			myList <double> list;

			for (int count = 0; count < 6; count++)
				list.push_back(1.1 + count);
			list.insert(4, 8);
			Assert::IsTrue((list.at(4) == 8));
		}

		TEST_METHOD(insertBoxwood_exception)
		{
			myList <boxwood> list;
			boxwood bw;

			bw.age = 5;
			bw.height = 5.5;
			try
			{
				list.insert(10, bw);
			}
			catch (const std::out_of_range &e)
			{
				Assert::AreEqual("insert: Seeking index is out of range", e.what());
			}
		}
	};

	TEST_CLASS(atTest)
	{
	public:
		TEST_METHOD(atInteger_exception)
		{
			myList <int> list;

			try
			{
				list.at(-10);
			}
			catch (const std::out_of_range &e)
			{
				Assert::AreEqual("at: Seeking index is out of range", e.what());
			}
		}

		TEST_METHOD(atDouble_threeElementsCheckPositions)
		{
			myList <double> list;

			list.push_back(4.4);
			list.push_back(-5.5);
			list.push_back(9.3);
			Assert::AreEqual((list.at(0)), 4.4);
			Assert::AreEqual((list.at(1)), -5.5);
			Assert::AreEqual((list.at(2)), 9.3);
		}

		TEST_METHOD(atBoxwood_oneElementCheckPositions)
		{
			myList <boxwood> list;
			boxwood bw;

			bw.age = 14;
			bw.height = 1.4;
			list.push_front(bw);
			Assert::IsTrue(list.at(0).age == 14);
			Assert::IsTrue(list.at(0).height == 1.4);
		}
	};

	TEST_CLASS(removeTest)
	{
		TEST_METHOD(removeInteger_exception)
		{
			myList <int> list;

			try
			{
				list.remove(10);
			}
			catch (const std::out_of_range &e)
			{
				Assert::AreEqual("remove: Seeking index is out of range", e.what());
			}
		}

		TEST_METHOD(removeDouble_inTheEndAndInTheBeginning)
		{
			myList <double> list;

			list.push_back(1.5);
			list.push_back(2.42);
			list.push_back(3.14);
			list.push_back(4.18);
			list.remove(0);
			list.remove(2);

			Assert::IsTrue(list.at(1) == 3.14);
		}

		TEST_METHOD(removeBoxwood_inTheMiddle)
		{
			myList <boxwood> list;
			boxwood bw;

			bw.age = 9;
			bw.height = 0.23;
			list.push_back(bw);
			bw.age = 10;
			bw.height = 0.18;
			list.push_back(bw);
			bw.age = 9;
			bw.height = 0.23;
			list.push_back(bw);
			list.remove(1);
			Assert::IsTrue(((list.at(0).age) == (list.at(1).age)) && ((list.at(0).height) == (list.at(1).height)));
		}
	};

	TEST_CLASS(getSizeTest)
	{
		TEST_METHOD(getSizeInteger_oneElementTrueStatement)
		{
			myList <int> list;
			list.push_back(2);
			Assert::IsTrue(list.get_size() == 1);
		}

		TEST_METHOD(getSizeDouble_oneElementFalseStatement)
		{
			myList <double> list;
			list.push_back(2);
			Assert::IsFalse(list.get_size() == 2);
		};

		TEST_METHOD(getSizeBoxwood_noElements)
		{
			myList <boxwood> list;
			Assert::IsFalse(list.get_size());
		}
	};

	TEST_CLASS(clearTest)
	{
		TEST_METHOD(clearInteger_tenElements)
		{
			myList <int> list;
			for (int count = 0; count < 10; count++)
				list.push_back(count);
			list.clear();

			Assert::IsTrue(!(list.get_size()));
		}

		TEST_METHOD(clearDouble_oneElement)
		{
			myList <double> list;
			list.push_back(48.88);
			list.clear();

			Assert::IsFalse(list.get_size());
		}

		TEST_METHOD(clearBoxwood_noElements)
		{
			myList <boxwood> list;
			list.clear();

			Assert::IsTrue(list.isEmpty());
		}
	};

	TEST_CLASS(setTest)
	{
		TEST_METHOD(setInteger_oneElement)
		{
			myList <int> list;
			list.insert(0, 5);
			list.set(0, 2);
			Assert::IsTrue((list.get_size() == 1) && (list.at(0) == 2));
		}

		TEST_METHOD(setDouble_fiveElementsSetInTheMiddle)
		{
			myList <double> list;
			for (int count = 0; count < 5; count++)
				list.push_back(0.89 + count);
			list.set(2, -1.7);
			Assert::IsTrue((list.at(2) == -1.7));
		}

		TEST_METHOD(setBoxwood_exception)
		{
			myList <boxwood> list;
			boxwood bw;

			bw.age = 43;
			bw.height = 4.3335;
			list.push_back(bw);
			try
			{
				bw.age = 90;
				bw.height = -88;
				list.set(-100, bw);
			}
			catch (const std::out_of_range &e)
			{
				Assert::AreEqual("set: Seeking index is out of range", e.what());
			}
		}
	};

	TEST_CLASS(isEmptyTest)
	{
		TEST_METHOD(isEmptyInteger_noElements)
		{
			myList <int> list;
			Assert::IsTrue(list.isEmpty());
		}

		TEST_METHOD(isEmptyDouble_oneElement)
		{
			myList <double> list;
			list.push_back(2.28);
			Assert::IsFalse(list.isEmpty());
		}

		TEST_METHOD(isEmptyBoxwood_afterClearing)
		{
			myList <boxwood> list;
			boxwood bw;

			bw.age = 0;
			bw.height = 0.77;
			list.push_front(bw);
			list.push_front(bw);
			list.push_front(bw);
			list.clear();
			Assert::IsTrue(list.isEmpty());
		}
	};
}
