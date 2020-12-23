#include <iostream>
#include <list>
#include <vector>
#include <sstream>
#include "Range.h"

using namespace std;
bool checkCase(string, bool);
void TestCase1();
void TestCase2();
void TestCase3();
void TestCase4();
void TestCase5();

int main()
{
    cout << "Range Class Testing!" << endl;
     TestCase1();
     TestCase2();
     TestCase3();
     TestCase4();
     TestCase5();
    return 0;
}

void TestCase1()
{
    Range<int>r(3, 11);
    stringstream out;
    out << r;

    if(checkCase("Case 1: sum()", r.sum() == 63)&&
      checkCase("Case 1: length()", r.length() == 9) &&
      checkCase("Case 1: average()", r.average() == 63 / 9) &&
      checkCase("Case 1: max()", r.max() == 11 ) &&
      checkCase("Case 1: min()", r.min() == 3)
    )
    {
        cout << "Test Case 1: Passed" << endl;
    }
    else
    {
        cout << "Test Case 1 Failed: Integer ascending range, default step" << endl;
    }
}
void TestCase2()
{
    Range<int>r(3, 12, 2);
    stringstream out;
    out << r;

    if(checkCase("Case 2: sum()", r.sum() == 35)&&
      checkCase("Case 2: length()", r.length() == 5) &&
      checkCase("Case 2: average()", r.average() == 35 / 5) &&
      checkCase("Case 2: max()", r.max() == 11 ) &&
      checkCase("Case 2: min()", r.min() == 3)
    )
    {
        cout << "Test Case 2: Passed" << endl;
    }
    else
    {
        cout << "Test Case 2 Failed: Integer ascending range; step = 2" << endl;
    }
}

void TestCase3()
{
    Range<double>r(7.5, 20.3, 2.5);
    stringstream out;
    out << r;

    if(checkCase("Case 3: sum()", r.sum() == 82.5)&&
      checkCase("Case 3: length()", r.length() == 6) &&
      checkCase("Case 3: average()", r.average() == 82.5 / 6) &&
      checkCase("Case 3: max()", r.max() == 20.0 ) &&
      checkCase("Case 3: min()", r.min() == 7.5)
    )
    {
        cout << "Test Case 3: Passed" << endl;
    }
    else
    {
        cout << "Test Case 3 Failed: Double ascending range; step = 2.5" << endl;
    }
}
void TestCase4()
{
    Range<int>r(12, 3, -2);
    stringstream out;
    out << r;

    if(checkCase("Case 4: sum()", r.sum() == 40)&&
      checkCase("Case 4: length()", r.length() == 5) &&
      checkCase("Case 4: average()", r.average() == 40 / 5) &&
      checkCase("Case 4: max()", r.max() == 12 ) &&
      checkCase("Case 4: min()", r.min() == 4)
    )
    {
        cout << "Test Case 4: Passed" << endl;
    }
    else
    {
        cout << "Test Case 4 Failed: Integer descending range; step = -2" << endl;
    }
}
void TestCase5()
{
    Range<double>r(20.0, 4.0, -2.5);
    stringstream out;
    out << r;

    if(checkCase("Case 5: sum()", r.sum() == 87.5)&&
      checkCase("Case 5: length()", r.length() == 7) &&
      checkCase("Case 5: average()", r.average() == 87.5 / 7) &&
      checkCase("Case 5: max()", r.max() == 20.0 ) &&
      checkCase("Case 5: min()", r.min() == 5.0)
    )
    {
        cout << "Test Case 5: Passed" << endl;
    }
    else
    {
        cout << "Test Case 5 Failed: Double descending range; step = -2.5" << endl;
    }
}

bool checkCase(string name, bool condition)
{
    if(!condition)
    {
        cout << "Failed: " << name << endl;
    }
    return condition;
}
