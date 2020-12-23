#include <iostream>
#include <string>

using namespace std;
 
class Person {
public:
  Person(string name, int amount) : name(name), amount(amount) {}
  //compare to objects
  bool operator >(Person g);
  bool operator ==(Person g);
  bool operator >=(Person g);
  bool operator <(Person g);
  bool operator <=(Person g);
  bool operator !=(Person g);
  //Compare object with int
  bool operator ==(int a);
  bool operator >=(int a);
  bool operator <(int a);
  bool operator >(int a);
  bool operator <=(int a);
  bool operator !=(int a);
  //put the object to the right 
  friend bool operator >(int a, const Person &g);
  friend bool operator <(int a, const Person &g);
  friend bool operator <=(int a, const Person &g);
  friend bool operator >=(int a, const Person &g);
  friend bool operator ==(int a, const Person &g);
  friend bool operator !=(int a, const Person &g);

  int getAmount() const;
  friend ostream& operator <<(ostream &out, const Person &g);
private:
  string name;
  int amount;
};
 
bool Person::operator >(Person g) {
  return amount > g.amount;
}

bool Person::operator ==(Person g){
    return amount == g.amount;
}

bool Person::operator >=(Person g){
    return amount >= g.amount;
}

bool Person::operator <(Person g){
    return amount < g.amount;
}

bool Person::operator <=(Person g){
    return amount <= g.amount;
}

bool Person::operator !=(Person g){
    return amount != g.amount;
}


//compare object with int
bool Person::operator ==(int a){
    return amount == a;
}
  bool Person::operator >=(int a){
      return amount >= a;
  }
  bool Person::operator <(int a){
      return amount < a;
  }
  bool Person::operator >(int a){
      return amount > a;
  }
  bool Person::operator <=(int a){
      return amount <= a;
  }
  bool Person::operator !=(int a){
      return amount != a;
  }
 
int Person::getAmount() const {
  return amount;
}

//put the object to the right
bool operator <(int a, const Person &g){
    return a < g.amount;
}

bool operator <=(int a, const Person &g){
    return a <= g.amount;
}

bool operator >=(int a, const Person &g){
    return a >= g.amount;
}

bool operator ==(int a, const Person &g){
    return a == g.amount;
}

bool operator !=(int a, const Person &g){
    return a != g.amount;
}

bool operator >(int a, const Person &g){
    return a > g.amount;
}

//ostream operator
ostream& operator <<(ostream &out, const Person &g) {
  out << g.name << ": " << g.amount;
  return out;
}


