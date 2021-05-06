#include "pch.h"
#include "CppUnitTest.h"
#include "..\Ford_and_Fulkerson_lab\Ford_and_Fulkerson.h"
#define TEST_CASE_DIRECTORY GetDirectoryName(__FILE__)
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Fordtest
{
	TEST_CLASS(lab3test)
	{
		string GetDirectoryName(string path) {
			const size_t last_slash_idx = path.rfind('\\');
			if (std::string::npos != last_slash_idx)
			{
				return path.substr(0, last_slash_idx + 1);
			}
			return "";
		}
	public:

		TEST_METHOD(empty_file)
		{
			string fileName = std::string(TEST_CASE_DIRECTORY) + "test_txt/test1.txt";
			Ford_and_Fulkerson test;
			int result;
			try
			{
				test.readList(fileName);
				result = test.MaxFlow();
			}
			catch (out_of_range e)
			{
				Assert::AreEqual(e.what(), "Graph is empty");
			}
		}
		TEST_METHOD(classic_test)
		{
			string fileName = std::string(TEST_CASE_DIRECTORY) + "test_txt/test2.txt";
			Ford_and_Fulkerson test;
			int result;
			test.readList(fileName);
			result = test.MaxFlow();
			Assert::AreEqual(result, 2000);
		}
		TEST_METHOD(different_edges)
		{
			string fileName = std::string(TEST_CASE_DIRECTORY) + "test_txt/test3.txt";
			Ford_and_Fulkerson test;
			int result;
			test.readList(fileName);
			result = test.MaxFlow();
			Assert::AreEqual(result, 30);
		}
		TEST_METHOD(linear_graph1)
		{
			string fileName = std::string(TEST_CASE_DIRECTORY) + "test_txt/test4.txt";
			Ford_and_Fulkerson test;
			int result;
			test.readList(fileName);
			result = test.MaxFlow();
			Assert::AreEqual(result, 10);
		}
		TEST_METHOD(linear_graph2)
		{
			string fileName = std::string(TEST_CASE_DIRECTORY) + "test_txt/test5.txt";
			Ford_and_Fulkerson test;
			int result;
			test.readList(fileName);
			result = test.MaxFlow();
			Assert::AreEqual(result, 10);
		}
		TEST_METHOD(linear_graph3)
		{
			string fileName = std::string(TEST_CASE_DIRECTORY) + "test_txt/test6.txt";
			Ford_and_Fulkerson test;
			int result;
			test.readList(fileName);
			result = test.MaxFlow();
			Assert::AreEqual(result, 10);
		}
		TEST_METHOD(big_graph)
		{
			string fileName = std::string(TEST_CASE_DIRECTORY) + "test_txt/test7.txt";
			Ford_and_Fulkerson test;
			int result;
			test.readList(fileName);
			result = test.MaxFlow();
			Assert::AreEqual(result, 7);
		}
	};
}
