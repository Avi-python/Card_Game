#ifndef CARD_INFO_INCLUDED
#define CARD_INFO_INCLUDED

#include "suit.h"

class CardInfo {
private:
    int rank;
    Suit* suit;
    int player_index;
    
public:
    CardInfo(int rank, Suit* suit, int player_index)
        : rank(rank), suit(suit), player_index(player_index) {}
    
    int get_rank() const { return rank; }
    Suit* get_suit() const { return suit; }
    int get_player_index() const { return playerIndex; }
};

#endif // CARD_INFO_INCLUDED