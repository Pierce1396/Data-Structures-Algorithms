#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <sstream>
#include <random>
#include "LinkedList.h"
#include "RapLyric.h"


/* Thank you for using my rap song lyric generator! This is just a silly little project I came up with to practice implementing a linked list. The Lyrics are courtesy of my
father-in-law, Dave Munk, a.k.a "White Chocolate"
Enjoy!
*/

using namespace std;

void townOrCity();
void carsOrMoney();
void foodOrSchool();
void display();


int main (){
    srand(time (NULL));
    string rapperName;
    cout << "Welcome to the rap song generator! Please enter your rapper name...." << endl;
    cin >> rapperName;
    cout << "Welcome " << rapperName << " let's start rhyming some mad lyrics! " << endl;

    RapLyric<string> RL;
    RL.townOrCity();
    RL.carsOrMoney();
    RL.foodOrSchool();
    cout << "Okay, your song is finished...." << endl;
    RL.display();

}
