#include <iostream>
#include <string>
#include "Pokemon.h"

using namespace std;

// For later
void PokemonFunction(Pokemon p);
void PokemonPointer(Pokemon *p);


int main() {
   // Like all fundamental types, I can declare variables of my custom type
   Pokemon bulbasaur;
   // The type is Pokemon; the name is pikachu.

   // To access members, I use the . operator.
   bulbasaur.mName = "Bulbasaur";
   bulbasaur.mNumber = 1;
   bulbasaur.mAttackPower = 30;
   bulbasaur.mDefense = 20;
   bulbasaur.mHitPoints = 100;

   bulbasaur.Speak();


   Pokemon pikachu;
   pikachu.mName = "Pikachu";
   pikachu.Speak();

   // I can copy Pokemon variables like any other variable type.
   // Doing so does a "member-wise" copy. We will come back to this later.
   Pokemon copy = bulbasaur;
   copy.Speak();

   // Call a function with a Pokemon. Remember the rules of passing variables.
   PokemonFunction(bulbasaur);
   bulbasaur.Speak(); // What prints?

   // What if I want a function to modify my Bulbasaur object? How should I
   // pass it?
   PokemonPointer(&bulbasaur);
   bulbasaur.Speak(); // What prints?


   // This code still has some problems before that we need to address.
   // 1. Nothing stops me from doing this:
   bulbasaur.mHitPoints = -1000;

   // 2. Can't give an initial value to a Pokemon.
   // Pokemon zapdos = ....? "Zapdos"? Hmm...

   // 3. Can't use nice operators like << or >>.
   // cout << bulbasaur ... would be nice, but can't... yet.

   // 4. When passing a Pokemon to a method, I must either pass a full duplicate
   //    (takes extra memory) or a pointer to my object (allows function to 
   //    modify my object). What if I want to save memory but not allow my 
   //    object to be modified?
}

void PokemonFunction(Pokemon pkmn) {
   pkmn.mName = "Mootwo"; // Does changing this change bulbasaur back in main? Why?
   pkmn.Speak();
}

void PokemonPointer(Pokemon *ptr) {
   ptr->mName = "Cleeone";
}