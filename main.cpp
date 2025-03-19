#include "card.cpp"
#include <iostream>

int main()
{
    Deck deck;
    std::vector<Card> cards = { Card(new Hearts(), 12), Card(new Spades(), 13), Card(new Clubs(), 1), Card(new Diamonds(), 10) };

    deck.set_deck(cards);
    deck.show_deck(3);

    return 0;
}