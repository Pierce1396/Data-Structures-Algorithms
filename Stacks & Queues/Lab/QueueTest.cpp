#include <iostream>
#include <string>
#include <cstdio>
#include <memory>
#include "queue.h"

using namespace std;
//Code to check the queue
void testqueue();
void errorHandeling();
void testTemplate();
//Aids in testing the program
bool checkTestMemory(string, int, int);
//Checks to see if the results match
bool checkTest(string, int, int);
bool checkTest(string, string, string);

int main()
{
	cout << "Testing queue\n" << endl;
	testqueue();
	errorHandeling();
	testTemplate();
	cout << "Done\n";
	system("pause");
	return 0;
}




//This helps with testing, do not modify.
void testqueue() {
	auto queue = make_unique< Queue <int> >();

	queue->enqueue(1);

	int data = queue->peek();
	queue->dequeue();
	checkTest("queue #1", 1, data);

	queue->enqueue(1);
	queue->enqueue(2);
	queue->enqueue(3);
	queue->enqueue(4);
	queue->enqueue(5);
	checkTest("queue #2", 1, queue->peek());
	queue->dequeue();
	checkTest("queue #3", 2, queue->peek());
	queue->dequeue();
	checkTest("queue #4", 3, queue->peek());
	queue->dequeue();
	checkTest("queue #5", 4, queue->peek());
	queue->dequeue();
	checkTest("queue #6", 1, queue->peek());
	queue->dequeue();

}




void errorHandeling() {
	// Now cover error handling
	auto queue = make_unique< Queue <int> >();
	string caughtError = "";
	int num;
	try {
		num = queue->peek();
	}
	catch (exception &e) {
		caughtError = "caught";
	}
	checkTest("queue #10", "caught", caughtError);
}
void testTemplate(){

		// Test some strings
		auto squeue = make_unique < Queue<string> >();

		squeue->enqueue("pencil");
		squeue->enqueue("pen");
		squeue->enqueue("marker");


		// Remove pen from the queue.
		string temp = squeue->peek(); // Get marker
		squeue->dequeue();               // Remove marker
		squeue->dequeue();               // Remove pen
		squeue->enqueue(temp);          // enqueue marker back in

									 // See if it worked
		checkTest("queue #12", "marker", squeue->peek());
		squeue->dequeue();
		checkTest("queue #13", "pencil", squeue->peek());
		squeue->dequeue();

	
	

}

//This helps with testing, do not modify.
bool checkTest(string testName, int whatItShouldBe, int whatItIs) {

	if (whatItShouldBe == whatItIs) {
		cout << "Passed " << testName << endl;
		return true;
	}
	else {
		cout << "***Failed test " << testName << " *** " << endl << "   Output was " << whatItIs << endl << "   Output should have been " << whatItShouldBe << endl;
		return false;
	}
}


//This helps with testing, comment it in when ready, but do not modify the code.
bool checkTest(string testName, string whatItShouldBe, string whatItIs) {

	if (whatItShouldBe == whatItIs) {
		cout << "Passed " << testName << endl;
		return true;
	}
	else {
		if (whatItShouldBe == "") {
			cout << "***Failed test " << testName << " *** " << endl << "   Output was " << whatItIs << endl << "   Output should have been blank. " << endl;
		}
		else {
			cout << "***Failed test " << testName << " *** " << endl << "   Output was " << whatItIs << endl << "   Output should have been " << whatItShouldBe << endl;
		}
		return false;
	}
}

//This helps with testing, do not modify.
bool checkTestMemory(string testName, int whatItShouldBe, int whatItIs) {

	if (whatItShouldBe == whatItIs) {
		cout << "Passed " << testName << endl;
		return true;
	}
	else {
		cout << "***Failed test " << testName << " *** " << endl << ".  ";
		cout << "You are manually managing " << whatItIs << " bytes in memory, but it should be " << whatItShouldBe << " bytes." << endl;
		return false;
	}
}