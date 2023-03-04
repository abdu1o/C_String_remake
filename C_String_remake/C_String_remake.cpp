#include <iostream>
#include "Class.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
	String str1("Hello ");
	String str2("World\n");

	String result;
	result = str1 + str2;
	result.Print();

	String equal_result;
	equal_result = str1 = str2;
	equal_result.Print();

	char ind_result = str1[2];
	cout << ind_result << endl;

	int char_result = str1('l');
	cout << char_result << endl;

	str1.ToInt();

	cout << endl;
}
