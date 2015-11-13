#include <iostream>
#include "Actor.h"
#include "Minion.h"
#include "Champion.h"
#include <random>
#include <vector>
using namespace std;

Actor *RandomActor();

int main() {
   // Polymorphism refers to the ability of a BASE CLASS pointer to point to
   // any object of a class that is DERIVED from the base class.
   Minion melee(250, 250, 50, 0, 23, 100);
   Champion garen(600, 600, 60, 30, 1, "Garen", "The Might of Demacia");

   // Now that Actor has an Attack class, we can make our actors do battle!
   garen.Attack(&melee);
   melee.Attack(&garen);
   cout << "After one attack:" << endl;
   cout << "Melee: " << melee.GetCurrentHitPoints() << " / " << 
      melee.GetMaxHitPoints() << " HP" << endl;
   cout << "Garen: " << garen.GetCurrentHitPoints() << " / " <<
      garen.GetMaxHitPoints() << " HP" << endl;

   Actor *a; // Actor is the base class
   // Polymorphism says I can point a at either melee or garen
   a = &melee;
   a = &garen;

   // This is allowed because every Minion "is-a" Actor, so an Actor* can point
   // to a Minion, or a Champion, or any other class that derives from Actor.

   // If we do this, then we are limited to using methods defined by the Actor
   // class. 
   cout << a->GetCurrentHitPoints() << endl;
   // Regardless of what a actually points to, we can ONLY use Actor methods.
   
   // Even though YOU AND I KNOW that a points to a Champion, this line will
   // not compile. Why do you suppose that is?
   // cout << a->GetName();   // Does the thing that a points to have a GetName
                              // method in reality? If yes, why can't we use it?

   // Suppose I'm willing to bet my life that a points to a Champion. I can use
   // "down casting" to convert it to a Champion pointer.
   Champion *c = (Champion*)a; // there is a better way to do this; more later.

   // I can now call my Champion methods on c, which points to the same object
   // that a does.
   cout << c->GetName() << endl;

   // Down-casting can be dangerous if you get the types wrong.
   a = &melee;
   c = (Champion*)a;
   cout << c->GetName() << endl; // ??????



   // Vectors of pointers.
   // Like all types, I can make a vector of Actor pointers.
   vector<Actor*> actors;
   actors.push_back(&melee); // I can push a Minion into an Actor... why?
   actors.push_back(&garen); // I can push a Champion into an Actor... why?
   // Iterating through a vector of pointers.
   for (vector<Actor*>::iterator itr = actors.begin(); itr != actors.end();
      itr++) {

      // *itr always gives me one element from the vector.. which would be of 
      // type Actor*. 
      cout << (*itr)->GetMaxHitPoints() << endl;
   }
   actors.clear(); // clear the vector for later.


   // One final example. Can I put heap-based objects into this vector?

   for (int i = 0; i < 5; i++)
      actors.push_back(RandomActor());
   // You bet!

   // Just remember... by putting heap objects in a vector, you must be careful
   // to not remove them without deleting them first.
   // DO NOT DO THIS:
   // actors.clear(); 
   // What would have happened???


   // Before clearing, you must walk the vector and delete each element.
   for (Actor *i : actors) { // remember this style loop?
      delete i; // this deletes the object, but the vector still have a pointer
                // to the now-deleted object.
   }
   actors.clear(); // now the vector has lost its pointers to the deleted stuff.

   return 0;

}

Actor *RandomActor() {
   random_device rd;
   default_random_engine engine(rd());
   uniform_int_distribution<int> d(0, 1);
   if (d(engine) == 0)
      return new Minion(1, 1, 1, 1, 1, 1); // new!!!
   else
      return new Champion(5, 5, 5, 5, 5, "Blah", "The Blah of Blah");
}