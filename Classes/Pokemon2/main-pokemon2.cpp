#include <iostream>
#include <string>
#include "Pokemon.h"
using namespace std;

int main() {
   Pokemon noname; // with no parameters, the default constructor is called
   Pokemon bulbasaur("Bulbasaur"); // call the one-parameter constuctor
   Pokemon pikachu("Pikachu", 25, 35, 55, 30); // call the other constructor.

   cout << noname.GetHitPoints() << endl;

   bulbasaur.SetHitPoints(-1000);

   bulbasaur.SetName("Ivysaur"); // call a mutator

   cout << bulbasaur.GetName() << endl; // call an accessor
   cout << bulbasaur.GetHitPoints() << endl;
   bulbasaur.Speak();
   // etc.
}