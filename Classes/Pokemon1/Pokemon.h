#ifndef __POKEMON_H
#define __POKEMON_H
// The lines above are an "include guard". They prevent this file from being
// inserted into a .cpp more than once. This is important for classes. The lines
// above must be paired with the final line of this file.

#include <string>
// We NEVER, EVER use namespaces in .h files. Sorry, get over it :).


// A class declaration.
class Pokemon {

public: // public is applied to blocks, not to individual items. 
        // Anything marked public can be used by anyone in the project.
   
   // Style guide requires member variables to start with "m".
   std::string mName;
   int mNumber;
   int mHitPoints;
   int mAttackPower;
   int mDefense;

   // Member functions do not start with "m", and are PascalCased.
   void Speak(); // We do NOT give method definitions in the .h file.

}; // note the semicolon


#endif