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
};

#endif