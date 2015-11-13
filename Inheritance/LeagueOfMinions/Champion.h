#ifndef __CHAMPION_H
#define __CHAMPION_H

#include "Actor.h"
#include <string>

class Champion : public Actor {
private:
   int mLevel;
   std::string mName;
   std::string mTitle;

public:
   Champion(int maxHitPoints, int currentHitPoints, int attackDamage,
      int defense, int level, const std::string &name, const std::string &title)
      : Actor(maxHitPoints, currentHitPoints, attackDamage, defense),
      mLevel(level), mName(name), mTitle(title) {

      if (level > 5) {
         SetMaxHitPoints(2 * GetMaxHitPoints());
      }
   }

   const std::string &GetName() const {
      return mName;
   }

   const std::string &GetTitle() const {
      return mTitle;
   }

   int GetLevel() const {
      return mLevel;
   }

   void SetName(const std::string &name) {
      mName = name;
   }

   void SetTitle(const std::string &title) {
      mTitle = title;
   }

   void SetLevel(int level) {
      mLevel = level;
   }
};


#endif