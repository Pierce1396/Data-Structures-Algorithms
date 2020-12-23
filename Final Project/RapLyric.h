#pragma once

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "LinkedList.h"

using namespace std;



template <typename T>
class RapLyric : public LinkedList<T>{
    public:
       void townOrCity();
       void carsOrMoney();
       void foodOrSchool();
    private:
        int randNum = (rand() % 4) + 1;
        string genTownOrCity = "We all live in a place, call it a city or town. It's that special little place we call our stomping ground. Let me hear about your city, why it makes you proud. Show your town some love, come on now shout it out. ";
        //cities
        string slc = "I live in the city that they call Salt Lake The womens' favorite food there is the wedding cake. ";
        string nyc = "Shout out from the city known as NYC In our harbor stands our lady we call liberty. ";
        string la = "Here in LA, it's just a West Coast thang Chilin in the hood where all my homies hang. ";
        string detroit = "Motor city, Detroit, it's where I hang my hat We got Motown records and a lot of stray cats. ";
        //towns
        string bountiful = "In the town of Bountiful, UT we never lock our doors and our kids can't play until they finish their chores. ";
        string emmett = "Emmett is a town that's found in Idaho Just exactly where it is only few peeps know. "; 
        string sitka = "Sitka, Ak, well now that's pretty remote. Wanna visit my town, you'd better jump on a boat. ";
        string bisbee = "Bisbee, Arizona was once a mining town so be careful if you visit not fall through the ground. ";
        //cars
        string genCar = "I take pride in my ride and I bet you do too Whether candy-Apple red or shiny midnight blue Cars are like stars, they help us navigate And I can promise you this, they'll score you points on a date. Gonna tell you all about some of my favorite wheels And I hope you buy your own cars at some fabulous deals. "; 
        string lambo = "I feel just like a genie in my Countach, Lamborghini the sitting room is cramped, motivates me to stay skinny. ";
        string ferrari = "Ladies scream, where are we,  I say in my Ferrari they laugh and say they're sorry, The whole drive was a party. ";
        string mustang = "I rolled up in my Mustang,  saw excitement in her eyes she asked if she could drive it, sped away to her surprise. ";
        string porche = "You'll never go wrong with a Porsche, least mine never let me down passengers always smiling, onlookers always frown. ";
        //money
        string genMoney = "Currently, we live by currency, it takes the place of gold or silver such divergency. Each country gets to choose the type of dough they prefer, I'll give a few examples so that you can confer. ";
        string dollar = "The dollar is the preferable earthly cash, but some say China is moving in fast. For now, it is the Benjamin we all agree that reigns as the predominant currency. ";
        string pound = "The pound has been around for a very long time, it's a literal unit of measurement from the silver mined. It's used by the Brits and that's about it, but that doesn't mean that it's not legit. ";
        string euro = "The Euro's very new to the world scene, it took eleven different currencies and found their mean. It unified the continent to a some degree, though not all countries would agree. ";
        string yuan = "The Yuan it is a unit of the RMB, it's not backed up by gold, silver or anything. It's just comi propaganda if you ask me, but I hear it's pretty cheap to buy a cup of tea. ";
        //food
        string genFood = "Food is good, food is great, The problem is I'm puttin way too much on my plate. I guess it's pretty easy to get carried away, especially when I'm eating at a prime rib buffet. We'll discuss the topic further in the next few lines, but first I need to finish these McDonald's fries. ";
        string cake = "White cake, yellow cake, red or brown, when it comes to cake I like to wolf it down. Cheese cake, short cake, bundt and pound, I'll even eat the one they call upsidedown. Rum cake, coffee cake, carrot and spice, angels food or devil's food, they both taste nice. ";
        string pizza = "Hand-tossed, fresh sauce with a butt load of cheese, fresh out the brick oven gotta me beggin please. Garlic dust, red pepper crushed, fold that slice in half, let it cool down or you will feel its wrath. First bite, pure delight, wash it down with a coke, if it isn't New York pizza it's a freakin joke. ";
        string hamburger = "If you want to win me over, there's no need to go further, that is, of course, if you have a quality hamburger. Cause every joint in town they're all making wild claims, you all know who I'm talking about, no need to name their names. Let's just say there's five guys who think they wear the crown, they're in and out like a bad habit, smashin everybody down. ";
        string mushroom = "Toadstools create dead fools and shrooms got fellas tripin, but the white button, man they're really something, so they the ones I'm hittin. Sauteed just right, they turn as black as night, from that first bite, taste buds take flight. Pile them on my stake, add them to my sauce, white button mushrooms be da boss. ";
        //school
        string oHigh = "";
        string mHigh = "";
        string bHigh = "";
        string eHigh = "";
};

template <typename T>
void RapLyric<T>::townOrCity(){
    string input;
    cout << "would you like to rap about a (t)own or (c)ity? " << endl;
    this->insert(genTownOrCity);
    cin >> input;
    if(input == "t"){
        if(randNum == 1){
            this->insert(bountiful);
        }else if(randNum == 2){
            this->insert(emmett);
        }else if(randNum == 3){
            this->insert(sitka);
        }else if(randNum == 4){
            this->insert(bisbee);
        }

    }else if(input == "c"){
        if(randNum == 1){
            this->insert(slc);
        }else if(randNum == 2){
            this->insert(nyc);
        }else if(randNum == 3){
            this->insert(la);
        }else if(randNum == 4){
            this->insert(detroit);
        }

    }
}

template <typename T>
void RapLyric<T>::carsOrMoney(){
    string input;
    cout << "would you like to rap about (c)ars or (m)oney? " << endl;
    cin >> input;
    if(input == "c"){
        this->insert(genCar);
        if(randNum == 1){
            this->insert(lambo);
        }else if(randNum == 2){
            this->insert(ferrari);
        }else if(randNum == 3){
            this->insert(mustang);
        }else if(randNum == 4){
            this->insert(porche);
        }

    }else if(input == "m"){
        this->insert(genMoney);
        if(randNum == 1){
            this->insert(dollar);
        }else if(randNum == 2){
            this->insert(pound);
        }else if(randNum == 3){
            this->insert(euro);
        }else if(randNum == 4){
            this->insert(yuan);
        }

    }

}

template <typename T>
void RapLyric<T>::foodOrSchool(){
    string input;
    cout << "would you like to rap about (f)ood or (s)chool? " << endl;
    cin >> input;
    if(input == "f"){
        this->insert(genFood);
        if(randNum == 1){
            this->insert(cake);
        }else if(randNum == 2){
            this->insert(pizza);
        }else if(randNum == 3){
            this->insert(hamburger);
        }else if(randNum == 4){
            this->insert(mushroom);
        }

    }else if(input == "s"){
        this->insert(genMoney);
        if(randNum == 1){
            this->insert(dollar);
        }else if(randNum == 2){
            this->insert(pound);
        }else if(randNum == 3){
            this->insert(euro);
        }else if(randNum == 4){
            this->insert(yuan);
        }

    }
}
