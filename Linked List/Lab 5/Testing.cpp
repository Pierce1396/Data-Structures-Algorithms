#include <iostream>
#include "FifthElement.h"

using namespace std;

int main () {
    FifthElement<int> f;
    for(int i = 1; i <= 10; i++){
        f.insert(i);
        
    }
    cout << f << endl;

    cout << f.getFifthElement() << endl;
    f.deleteFifthElement();
    cout << f << endl;
    f.insertNewFifthElement(42);
    cout << f << endl;
    f.swapFourthAndFifthElement();
    cout << f << endl;
}