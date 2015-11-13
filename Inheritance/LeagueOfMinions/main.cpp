#include <iostream>
#include "Actor.h"
#include "Minion.h"
#include "Champion.h"
using namespace std;

void PrintStats(Actor *a);

int main() {
   Minion melee(250, 250, 50, 0, 23, 100);

   // Even tough the Minion class itself does not have "GetCurrentHitPoints",
   // it has inherited the method from Actor, so it really does have a copy.
   cout << melee.GetCurrentHitPoints();
   // Minion also has whatever fields and methods were defined in its own class.
   cout << melee.GetGoldValue() << endl;

   Champion garen(600, 600, 60, 30, 1, "Garen", "The Might of Demacia");
   cout << garen.GetTitle() << endl;


   // "Polymorphism": the ability of a variable declared as a pointer to a
   // base class object to actually point to a derived class object.
   Actor *t = &melee;
   // We say that "Minion is-a Actor", so we can point an Actor at a Minion.

   // This lets me write functions that work on all Actors, regardless if they
   // are minions or champions, as below.
   PrintStats(&melee);
   
   garen.SetCurrentHitPoints(550);
   PrintStats(&garen);
}

void PrintStats(Actor *a) {
   cout << "Actor: " << a->GetCurrentHitPoints() << " / " << a->GetMaxHitPoints()
      << " HP; " << a->GetAttackDamage() << " attack; " << a->GetDefense()
      << " defense" << endl;
}