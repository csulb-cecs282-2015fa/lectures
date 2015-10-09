#ifndef __CARD_H  // huh???
#define __CARD_H

#include <string>

/*
This class represents a single playing card in a standard 52-card deck.
*/
class Card {
private:
   // The private member variables of the class will represent its state.

   char mKind; // numerical value of card; 11 = J, 12 = Q, 13 = K, 14 = Ace
   char mSuit; // 0 = Spade, 1 = Club, 2 = Diamond, 3 = Heart

public:
   // A "default constructor": one that takes no arguments. Will be needed later
   Card();

   // A constructor taking enough information to set up a Card object.
   Card(char kind, char suit);

   // Mutators for Kind and Suit.
   void SetKind(char kind);
   void SetSuit(char suit);

   // An operator for printing a card to cout:
   friend std::ostream& operator<<(std::ostream& lhs, const Card &rhs);
   // operators for comparing cards.
   friend bool operator<(const Card &lhs, const Card &rhs);
   friend bool operator==(const Card &lhs, const Card &rhs);
};

#endif