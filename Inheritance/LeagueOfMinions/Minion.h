#ifndef __MINION_H
#define __MINION_H
#include "Actor.h"
class Minion : public Actor {
private:
   int mGoldValue;
   int mExperienceValue;

public:
   Minion(int maxHitPoints, int currentHitPoints, int attackDamage, int defense,
      int goldValue, int experienceValue)
      // Before constructing the part of the object that is a Minion, we first 
      // construct the Actor part of the object.
      : Actor(maxHitPoints, currentHitPoints, attackDamage, defense),
      mGoldValue(goldValue), mExperienceValue(experienceValue) {
   }

   int GetGoldValue() const {
      return mGoldValue;
   }

   int GetExperienceValue() const {
      return mExperienceValue;
   }

   void SetGoldValue(int goldValue) {
      mGoldValue = goldValue;
   }

   void SetExperienceValue(int experienceValue) {
      mExperienceValue = experienceValue;
   }
};

#endif