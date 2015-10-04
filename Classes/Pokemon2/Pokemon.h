#ifndef __POKEMON_H
#define __POKEMON_H

#include <string>

class Pokemon {
private:
   // Private members cannot be accessed outside the class.
   std::string mName;
   int mNumber;
   int mHitPoints;
   int mAttackPower;
   int mDefense;
   // Now, no one can say something like:
   // bulbasaur.mHitPoints = -1000;

public:
   // A method with the same name as a class is called the constructor. It is 
   // used to initialize a new instance of the class.
   Pokemon(); // "Default constructor": no parameters.

   // Constructors can be overloaded as long as they have different parameters.
   Pokemon(const std::string &name); // Constructor with only a name.

   Pokemon(const std::string &name, int number, int hitPoints, int attack,
      int defense);

   // Accessor methods. Since our variables are now private, others need a way
   // to read them.
   const std::string& GetName();
   int GetNumber(); // why isn't this const int &GetNumber???

   int GetHitPoints(); 
   // etc.



   // What if someone wants to change the variables? We need mutator methods.
   void SetName(const std::string &name);
   void SetNumber(int number);
   void SetHitPoints(int hitPoints);

   // Other methods.
   void Speak(); 

};


#endif