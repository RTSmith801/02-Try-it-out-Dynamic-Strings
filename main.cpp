/**
 * @file: Url.cpp
 * @assignment_name: 02: Try it out: Dynamic Strings
 * @author: Rick Smith (rickysmith@mail.weber.edu)
 * @start-date: 11/07/2022
 * @finish-date: 11/09/2022
 * @brief: This program will cover Inheritance and Memory Management with dynamic allocated memory.
 *
 */


#include "Url.h"
#include "DynamicString.h"
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <string>

using std::cout;
using std::endl;
using std::invalid_argument;
using std::strcmp;
using std::string;
template <typename T>
void test(int testNum, int& correct, T actual, T expected) {
	if (actual == expected) {
		correct++;
		cout << "Passed Test " << testNum << endl;
	}
	else {
		cout << "***Failed Test " << testNum << "***" << endl;
		cout << "Actual: " << actual << " Expected: " << expected << endl;
	}
}
void testString(int testNum, int& correct, const char* actual, const char*
	expected) {
	if (actual && expected && strcmp(actual, expected) == 0) {
		correct++;
		cout << "Passed Test " << testNum << endl;
	}
	else {
		cout << "***Failed Test " << testNum << "***" << endl;
		if (actual && expected) {
			cout << "Actual: " << actual << " Expected: " << expected << endl;
		}
	}
}
int main() {

    //Url u7("HTTP://CPLUSPLUS.COM/index.html?version=c++11#Reference");


	int correct = 0;
	cout << "---------------Memory Management Tests--------------" << endl;
	DynamicString s1("abc");
	DynamicString* s2 = new DynamicString(s1);
	s2->operator[](0) = 'b';
	test(1, correct, s2->operator[](0), 'b');
	test(2, correct, s1[0], 'a');
	DynamicString* s3 = new DynamicString(*s2);
	DynamicString s4("baa baa");
	*s3 = s4;
	s3->operator[](0) = 'a';
	test(3, correct, s3->operator[](0), 'a');
	test(4, correct, s4[0], 'b');
	delete s3;
	delete s2;
	cout << "--------URL Parsing Tests--------" << endl;
	/*Scheme and Host*/
	Url u1("http://www.icarus.cs.weber.edu");
	Url u2("https://icarus.cs.weber.edu");
	Url u3("smb://kfeuz@athena.cs.weber.edu");
	Url u4("file:///home/cs2420/assignment3/");
	Url u5("http://icarus.cs.weber.edu/~kfeuz/index.html");
	Url u6("https://weber.edu/index.html?lang=en");
	Url u7("http://cplusplus.com/index.html?version=c++11#Reference");
	Url u8("https://wikipedia.org/index.html#Help");
	cout << "--------Compare--------" << endl;
	/*Compare*/
	test(5, correct, u1.compare(u2) < 0, true);
	test(6, correct, u3.compare(u4) > 0, true);
	test(7, correct, u6.compare(u7) > 0, true);
	test(8, correct, u8.compare(u8), 0);
	Url u9("HTTP://cplusplus.com/index.html?version=c++11#Reference");
	test(9, correct, u7.compare(u9), 0);
	Url u10("http://CPLUSPLUS.COM/index.html?version=c++11#Reference");
	test(10, correct, u10.compare(u7), 0);
	Url u11("http://cplusplus.com/INDEX.html?version=c++11#Reference");
	test(11, correct, u7.compare(u11) > 0, true);
	Url u12("https://WEBER.edu/index.html?lang=en");
	test(12, correct, u6.compare(u12), 0);
	Url u13("HTTPS://weber.edu/INDEX.html?lang=en");
	test(13, correct, u6.compare(u13) > 0, true);
	cout << "--------Error Checking--------" << endl;
	try {
		Url u21("google.com");//invalid argument(no scheme)
		test(14, correct, 0, 1);
	}
	catch (invalid_argument) {
		test(14, correct, 0, 0);
	}
	try {
		Url u30("/index.html");//invalid argument (relative url)
		test(15, correct, 0, 1);
	}
	catch (invalid_argument) {
		test(15, correct, 0, 0);
	}
	try {
		Url u27("://weber.edu");//invalid argument(no scheme)
		test(16, correct, 0, 1);
	}
	catch (invalid_argument) {
		test(16, correct, 0, 0);
	}
	cout << endl << "----------Results----------" << endl;
	cout << "Passed " << correct << "/" << 16 << " tests" << endl;
}