#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.2recur/Lab_12.2recur.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            Elem* first = NULL, * last = NULL;
            for (int i = 0; i < 5; i++) {
                if (first == NULL)
                {
                    first = new Elem;
                    first->info = i;
                    first->link = NULL;
                    last = first;
                }
                else
                {
                    Input(first->link, last, i);
                }
                bool t = Сheck(first);
                Assert::AreEqual(t, false);
            }
		}
	};
}
