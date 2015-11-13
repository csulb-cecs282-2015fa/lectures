#ifndef __ACTOR_H
#define __ACTOR_H

#include <string>

class Actor {
private:
   int mMaxHitPoints;
   int mCurrentHitPoints;
   int mAttackDamage;
   int mDefense;

public:
   // We usually implement class methods in a .cpp file, but we can technically
   // put them in the .h file. I do this here for brevity only.

   Actor(int maxHitPoints, int currentHitPoints, int attackDamage, int defense)
      : mMaxHitPoints(maxHitPoints), mCurrentHitPoints(currentHitPoints), 
      mAttackDamage(attackDamage), mDefense(defense) {
   }

   int GetMaxHitPoints() const {
      return mMaxHitPoints;
   }

   int GetCurrentHitPoints() const {
      return mCurrentHitPoints;
   }

   int GetAttackDamage() const {
      return mAttackDamage;
   }

   int GetDefense() const {
      return mDefense;
   }

   void SetMaxHitPoints(int maxHitPoints) {
      mMaxHitPoints = maxHitPoints;
   }

   void SetCurrentHitPoints(int currentHitPoints) {
      mCurrentHitPoints = currentHitPoints;
   }

   void SetAttackDamage(int attackDamage) {
      mAttackDamage = attackDamage;
   }

   void SetDefense(int defense) {
      mDefense = defense;
   }

   // New: attack another Actor.
   void Attack(Actor *a) {
      // Remember, a can point to any Actor type. We will use one formula for
      // attacking regardless of target type.

      // Formula: damage dealt = my attack * (100 / (100 + opponent defense)).
      int damage = (int)(mAttackDamage * (100.0 / (100 + a->GetDefense())));
      if (damage > a->GetCurrentHitPoints())
         a->SetCurrentHitPoints(0);
      else
         a->SetCurrentHitPoints(a->GetCurrentHitPoints() - damage);
   }
};

#endif