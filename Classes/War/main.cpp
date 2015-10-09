#include <iostream>
#include <string>
#include "Card.h"
#include "Deck.h"

using namespace std;

// Play a game of War. Using the Deck and Card classes, set up two decks of 
// cards and shuffle them. Then repeatedly deal 1 card to each player and 
// compare the cards. Whichever card is greater wins that round.
int main(int argc, char* argv[]) {

   // Build a deck for player 1.
   Deck d1;
   cout << d1 << endl; // Prints in standard unshuffled deck order... why?

   // Shuffle and demonstrate that the shuffle worked.
   d1.Shuffle();
   cout << d1 << endl;

   // Shuffle a deck for player 2.
   Deck d2;
   d2.Shuffle();
   

   cout << endl << endl << "Let's play WAR!" << endl;
   while (d1.GetCount() > 0) {
      Card c1 = d1.DealOne(), c2 = d2.DealOne();

      cout << c1 << " vs. " << c2 << " ... " <<
         (c1 == c2 ? "Tie!" : c1 < c2 ? "Player 2 wins!" : "Player 1 wins!") << endl;

      char cont;
      cout << "Continue? y/n: ";
      cin >> cont;
      if (cont != 'y')
         break;
      cout << endl;
   }
}
