#include "Card.h"
#include <iostream>
#include <string>
using namespace std;

Card::Card(char kind, char suit) :
   mKind(kind), mSuit(suit) {
}

Card::Card() : mKind(0), mSuit(0) { 
}

void Card::SetKind(char kind) {
   // validate the kind
   if (kind >= 2 && kind <= 14)
      mKind = kind;
}

void Card::SetSuit(char suit) {
   // validate the suit
   if (suit >= 0 && suit <= 3)
    mSuit = suit;
}

ostream& operator<<(ostream& lhs, const Card& rhs) {
   string strValue; // a string's default constructor makes it empty.
   if (rhs.mKind <= 10)
      strValue += std::to_string(rhs.mKind);
   else {
      strValue += (
         rhs.mKind == 11 ? "Jack" :
         rhs.mKind == 12 ? "Queen" :
         rhs.mKind == 13 ? "King" :
         "Ace"
         );
   }
   strValue += " of ";

   string suits[] = { "Spades", "Clubs", "Diamonds", "Hearts" };
   strValue += suits[rhs.mSuit];
   lhs << strValue;
   return lhs;
}

bool operator<(const Card &lhs, const Card &rhs) {
   return lhs.mKind < rhs.mKind;
}

bool operator==(const Card &lhs, const Card &rhs) {
   return lhs.mKind == rhs.mKind;
}