#include <iostream>
#include <string>
#include "Pokemon.h"

using namespace std;

// Implement the constructors.
// Constructors do not have a return type; simply scope them.


// We'll start with the full-parameter destructor.
Pokemon::Pokemon(const string &name, int number, int hitPoints, int attack,
   int defense)
   : mName(name), mNumber(number), mHitPoints(hitPoints), mAttackPower(attack),
     mDefense(defense) {
   // This is called an initializer list. Its job is to initialize each member
   // variable with a value.

   // This is technically the same as doing
   // mName = name;
   // mNumber = number; etc
   // as you would in Java. It's more efficient, but you don't need to know 
   // the intimate details.
}

// The default constructor should initialize the member variables to some
// appropriate default values.
Pokemon::Pokemon() 
   // Instead of repeating an initializer list, we can "call" the other 
   // constructor and give it "default" values.
   : Pokemon("", 0, 0, 0, 0) {
}

Pokemon::Pokemon(const string &name)
   : Pokemon(name, 0, 0, 0, 0) {
}

// Implementation of accessor functions.
const string &Pokemon::GetName() {
   return mName;
}

int Pokemon::GetHitPoints() {
   return mHitPoints;
}

int Pokemon::GetNumber() {
   return mNumber;
}

// Implementation of mutator functions.
void Pokemon::SetName(const string &name) {
   mName = name;
}

void Pokemon::SetHitPoints(int hitPoints) {
   if (hitPoints >= 0)
      mHitPoints = hitPoints;
}

void Pokemon::Speak() {
   string phrase = mName.substr(0, (mName.size() + 1) / 2);
   cout << phrase << ", " << phrase << "!" << endl;
}