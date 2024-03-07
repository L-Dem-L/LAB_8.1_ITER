#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_8.1_ITER/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestCount)
		{
			// Arrange
			char str1[] = "abc***def***ghi***jkl";
			char str2[] = "***";
			char str3[] = "abc";

			// Act
			int count1 = Count(str1);
			int count2 = Count(str2);
			int count3 = Count(str3);

			// Assert
			Assert::AreEqual(3, count1);
			Assert::AreEqual(1, count2);
			Assert::AreEqual(0, count3);
		}

		TEST_METHOD(TestChange)
		{
			// Arrange
			char str1[] = "abc***def***ghi***jkl";
			char str2[] = "abc";

			// Act
			char* result1 = Change(str1);
			char* result2 = Change(str2);

			// Assert
			Assert::AreEqual("abc!!def!!ghi!!jkl", result1);
			Assert::AreEqual("abc", result2);

			// Clean up
			delete[] result1;
			delete[] result2;
		}
	};
}
