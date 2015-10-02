// Any methods declared in a class .h file should be defined in a corresponding
// .cpp file with the same name.

#include <iostream>
#include <string>
#include "Pokemon.h"

using namespace std;

// To define a class function, we can't just write the name... why?
// void Speak() { ... why doesn't this work?



// Instead, we "scope" the definition.
void Pokemon::Speak() {
   // Many Pokemon "speak" by repeating the first half of their name.
   string phrase = mName.substr(0, (mName.size() + 1) / 2);
   // What is mName referring to here?


   cout << phrase << ", " << phrase << "!" << endl;
}