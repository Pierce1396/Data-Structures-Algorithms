 
#include <iostream>
#include "Person.h"
 
using namespace std;
 
int main() {
   
  Person bt("Bart", 10);
  Person hm("Homer", 42);
  Person mg("Marge", 42);
 
  //Comparing using >
  if (hm > bt) {
    cout << "Older: " << hm << endl;
    cout << "Younger: " << bt << endl;
  }
  //Comparing using ==
  if(hm == mg){
    cout << "Same Age: " << endl;
    cout << hm << endl;
    cout << mg << endl;
  }

  //compare using >=
  if(hm >= mg){
    cout << "Older or Same Age: " << endl;
    cout << hm << endl;
    cout << mg << endl;
  }

  //compare using <

  if(bt < hm){
    cout << "Older: " << hm << endl;
    cout << "Younger: " << bt << endl;
  }

  //compare using <=
  if(bt <= mg){
    cout << "Younger or Same Age: " << endl;
    cout << bt << endl;
    cout << mg << endl;
  }

  //compare using !=
  if(hm != bt){
    cout << "Not the Same Age: " << endl;
    cout << hm << endl;
    cout << bt << endl;
  }

  //compare person to a number
  if (bt < 21) {
		cout << bt << "  too young for Moes" << endl;
    }

    
  if (hm > 5) {
    cout << "Older: " << hm << endl;
    
  }
  
  if(hm == 42){
    cout << "Same Age: " << endl;
    cout << hm << endl;
    
  }

  
  if(hm >= 8){
    cout << "Older or Same Age: " << endl;
    cout << hm << endl;
    
  }

  

  if(bt < 20){
    
    cout << "Younger: " << bt << endl;
  }

  
  if(bt <= 10){
    cout << "Younger or Same Age: " << endl;
    cout << bt << endl;
    
  }

  
  if(hm != 88){
    cout << "Not the Same Age: " << endl;
    cout << hm << endl;
    
  }
  
  //putting the object to the right
  if (21 > bt) {
		cout << bt << " less than 21" << endl;
	}

 if (9 < bt) {
		cout << bt << " greater than 9" << endl;
	}

 if (10 <= bt) {
		cout << bt << " less than or equal to 10" << endl;
	}

 if (52 >= bt) {
		cout << bt << " less than or equal to 52" << endl;
	}

 if (10 == bt) {
		cout << bt << " equal to 10" << endl;
	}

 if (10000 != bt) {
		cout << bt << " not equal to 10000" << endl;
	}

}