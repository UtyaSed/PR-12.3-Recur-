#include "pch.h"
#include "CppUnitTest.h"
#include "../PR 12.3(Recur)/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* start;
			start = new Elem;
			start->info = 80;
			start->next = new Elem;
			start->next->info = 70;
			start->next->next = new Elem;
			start->next->next->info = 60;

			Elem* last = start->next->next;

			bool x = check(start, 0);

			Assert::AreEqual(x, false);
		}
	};
}