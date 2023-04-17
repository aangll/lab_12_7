#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_12_7/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			string name1 = "moko";
			string phone1 = "123";
			double arear1 = 12;

			string name2 = "molo";
			string phone2 = "124";
			double arear2 = 123;

			string name3 = "moso";
			string phone3 = "125";
			double arear3 = 1234;

			Subscriber* head = nullptr;

			addSubscriber(head, name1,phone1, arear1);
			addSubscriber(head, name2, phone2, arear2);
			addSubscriber(head, name3, phone3, arear3);

			bool yes;

			if (head->last_name == name1) {
				yes = true;
			}

			Assert::IsTrue(yes);

		}
	};
}
