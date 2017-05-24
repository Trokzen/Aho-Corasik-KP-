#pragma once
#include "stdafx.h"
#include "CppUnitTest.h"
#include "Fun.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	//public:
		
		TEST_METHOD(TestMethod1)//Ïðîâåðèì íà âõîæäåíèå 1 ñòðîêó(ïîëüçîâàòåëü ââîäèò ñòðîêè)
		{
			A_C Test;
			Test.setText("addadda");
			Test.AddInTreeStr("a");
			string str = "sdds";
			Assert::AreEqual(str, Test.ACSetup());
		}
		TEST_METHOD(TestMethod2)//Ïðîâåðèì íà âõîæäåíèå íåñêîëüêî ñòðîê(ïîëüçîâàòåëü ââîäèò ñòðîêè)
		{
			A_C Test;
			Test.setText("addada");
			Test.AddInTreeStr("a");
			Test.AddInTreeStr("d");
			string str = "addada";
			Assert::AreEqual(str, Test.ACSetup());
		}
		TEST_METHOD(TestMethod3)//Èíúåêöèÿ îøèáêè â ïîèñê ñòðîê(ïîëüçîâàòåëü ââîäèò ñòðîêè)
		{
			A_C Test;
			Test.setText("addada");
			Test.AddInTreeStr("a");
			Test.AddInTreeStr("d");
			string str = "ddadaa";
			Assert::AreNotEqual(str, Test.ACSetup());
		}
		TEST_METHOD(TestMethod4)//Ïðîâåðêà íà îòêðûòèå ôàéëà
		{
			A_C Test;
			string str;
			char chBuff;

			fstream readFile("text.txt");
			if (readFile) {
				while (!readFile.eof()) {
					readFile.get(chBuff);
					if (chBuff != '\n')
						str += chBuff;
				}
				str.erase(str.length() - 1, 1);
				readFile.close();
				Assert::AreEqual(str, Test.OpenFile());
			}
		}
		TEST_METHOD(TestMethod5)//Ïðîâåðêà íà îòêðûòèå ôàéëà//èíúåêöèÿ îøèáêè
		{
			A_C Test;
			string str;
			char chBuff;

			fstream readFile("text.txt");
			if (readFile) {
				while (!readFile.eof()) {
					readFile.get(chBuff);
					if (chBuff != '\n')
						str += chBuff;
				}
				str.erase(str.length() - 2, 1);
				readFile.close();
				Assert::AreNotEqual(str, Test.OpenFile());
			}
		}
		TEST_METHOD(TestMethod6)//Ïðîâåðêà íà íóìåðàöèþ íàéäåííûõ ñòðîê
		{
			A_C Test;
			Test.setText("ada");
			Test.AddInTreeStr("a");
			Test.ACSetup();
			int i = 2;
			Assert::AreEqual(i,Test.ResultInt);
		}
		TEST_METHOD(TestMethod7)//Ïðîâåðêà íà íóìåðàöèþ íàéäåííûõ ñòðîê//èíúåêöèÿ îøèáêè
		{
			A_C Test;
			Test.setText("add");
			Test.AddInTreeStr("a");
			Test.ACSetup();
			int i = 1;
			Assert::AreNotEqual(i,Test.ResultInt);
		}
	};

}
