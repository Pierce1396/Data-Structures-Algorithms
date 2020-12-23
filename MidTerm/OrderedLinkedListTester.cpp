#include<iostream>
#include<sstream>
#include "OrderedLinkedList.h"


void testNumbers();
void testException();
void testStrings();
void testDelete();
void testOperator();


bool checkTest(std::string testName, std::string whatItShouldBe, std::string whatItIs);
bool checkTest(std::string testName, int whatItShouldBe, int whatItIs);
bool checkTestMemory(std::string testName, int whatItShouldBe, int whatItIs);

int main()
{
	testNumbers();
	testException();
	testStrings();
	testDelete();
	testOperator();
	system("pause");
	return 0;
}



//This helps with testing, do not modify.
void testNumbers() {

	OrderedLinkedList<int> si;
	si + 3 + 1 + 2 + 5 + 4;
	std::ostringstream out;
	out << si;
	//Test just to make sure the data went in the list.
	checkTest("test #1: adding elements", "1 2 3 4 5", out.str());

	//Test retrieving item.
	int item = si.peek(0);
	checkTest("test #2: checking first element", 1, item);
	item = si.peek(2);
	checkTest("test #3: checking middle element", 3, item);
	item = si.peek(4);
	checkTest("test #4: checking last element", 5, item);
	

}

void testException() {
	OrderedLinkedList<int> si;
	for (int i = 1; i < 4; i++) {
		si.insert(i);
	}

	//Try to access out of bounds.
	std::string caughtError = "";
	try {
		int item = si.peek(3);
		item = item;

	}
	catch (std::exception& e) {
		caughtError = "caught";
	}
	checkTest("test #5: checking exception ", "caught", caughtError);
}

void testStrings() {

	OrderedLinkedList<std::string> ss;
	ss.insert("Broccoli");
	ss.insert("Carrot");
	ss.insert("Apple");
	ss.insert("Eggplant");
	ss.insert("Dumpling");

	checkTest("test #6: testing strings", "Apple", ss.peek(0));
	checkTest("test #7: testing strings order", "Carrot", ss.peek(2));
}


void testDelete() {
	OrderedLinkedList<int> si;
	for (int i = 10; i < 20; i++) {
		si.insert(i);
	}

	si.remove(0);
	std::ostringstream out;
	out << si;
	//Test just to make sure the data went in the list.
	checkTest("test #7: deleting first item", "11 12 13 14 15 16 17 18 19", out.str());
	si.remove(8);
	out.str("");
	out.clear();
	out << si;
	checkTest("test #8: deleting last item", "11 12 13 14 15 16 17 18", out.str());
	si.insert(20);
	out.str("");
	out.clear();
	out << si;
	checkTest("test: #9: adding after deleting last item", "11 12 13 14 15 16 17 18 20", out.str());
	bool test = true;
	try {
		test = true;
		si.remove(22);
	}
	catch (std::exception &e) {
		test = false;
	}
	checkTest("test #10: exceeding the list", test, false);
}

void testOperator() {
	OrderedLinkedList<int> lst;
	lst + 5 + 3 + 1 + 2 + 4;
	int num = lst[0];
	checkTest("test #11: Operator[]", num==1, true);
	bool test = false;
	try {
		num = lst[10]; //exceeds list size
	}
	catch (std::exception &e) {
		test = true;
	}
	checkTest("test #12: Operator[] out of bounds", test, true);
}



//This helps with testing, do not modify.
bool checkTest(std::string testName, std::string whatItShouldBe, std::string whatItIs) {

	if (whatItShouldBe == whatItIs) {
		std::cout << "Passed " << testName << std::endl;
		return true;
	}
	else {
		std::cout << "****** Failed test " << testName << " ****** " << std::endl << "     Output was " << whatItIs << std::endl << "     Output should have been " << whatItShouldBe << std::endl;
		return false;
	}
}

//This helps with testing, do not modify.
bool checkTest(std::string testName, int whatItShouldBe, int whatItIs) {

	if (whatItShouldBe == whatItIs) {
		std::cout << "Passed " << testName << std::endl;
		return true;
	}
	else {
		std::cout << "****** Failed test " << testName << " ****** " << std::endl << "     Output was " << whatItIs << std::endl << "     Output should have been " << whatItShouldBe << std::endl;
		return false;
	}
}

//This helps with testing, do not modify.
bool checkTestMemory(std::string testName, int whatItShouldBe, int whatItIs) {

	if (whatItShouldBe == whatItIs) {
		std::cout << "Passed " << testName << std::endl;
		return true;
	}
	else {
		std::cout << "***Failed test " << testName << " *** " << std::endl << "  You lost track of " << whatItIs << " bytes in memory!" << std::endl;
		return false;
	}
}

