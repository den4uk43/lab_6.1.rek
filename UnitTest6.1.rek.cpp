#include "pch.h"
#include "CppUnitTest.h"
#include "/ap_labs/lab6.1rek/lab6.1rek/lab6.1.rek.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest61rek
{
	TEST_CLASS(UnitTest61rek)
	{
	public:
		
        TEST_METHOD(TestPredict)
        {
            Assert::IsTrue(predict(-2));
            Assert::IsFalse(predict(-3));
            Assert::IsFalse(predict(4));
            Assert::IsFalse(predict(0));
        }

        TEST_METHOD(TestF)
        {
            const int size = 50;
            int p[size];
            F(p, size, -20, 34);
            for (int i = 0; i < size; i++)
            {
                Assert::IsTrue(p[i] >= -20 && p[i] <= 34);
            }
        }

        TEST_METHOD(TestCount)
        {
            int p[] = { -2, 3, -4, 5, 0, -7, 8, -10 };
            int t = countElements(p, 8);
            Assert::AreEqual(3, t);
        }

        TEST_METHOD(TestSum)
        {
            int p[] = { -2, 3, -4, 5, 0, -7, 8, -10 };
            int t = sumElements(p, 8);
            Assert::AreEqual(-16, t);
        }

        TEST_METHOD(TestReplace)
        {
            int p[] = { -2, 3, -4, 5 };
            replaceElements(p, 4);
            Assert::AreEqual(0, p[0]);
            Assert::AreEqual(3, p[1]);
            Assert::AreEqual(0, p[2]);
            Assert::AreEqual(5, p[3]);
        }
	};
}
