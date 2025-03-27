#include "ninenine.h"

#include <iostream>
#include <algorithm>
#include <random>

NineNine::NineNine(int maxPlayers, int initialHandSize) 
    : current_state(GameState::NOT_STARTED),
      current_player_index(0),
      initial_hand_size(initialHandSize),
      max_players(maxPlayers) {}

void NineNine::setup_game() {
    
    this->setup_deck();
    this->deal_initial_cards();
    this->current_player_index = 0;
}

void NineNine::setup_deck() {
    std::vector<Card> cards;
    
    Hearts hearts;
    Diamonds diamonds;
    Clubs clubs;
    Spades spades;
    
    for (int rank = 1; rank <= 13; ++rank) {
        cards.push_back(Card(&hearts, rank));
        cards.push_back(Card(&diamonds, rank));
        cards.push_back(Card(&clubs, rank));
        cards.push_back(Card(&spades, rank));
    }
    
    game_deck.set_deck(cards);
    game_deck.shuffle();
    
    std::cout << "Shuffle done.\n";
}

void NineNine::deal_initial_cards() {
    for(int i = 0; i < players.size(); i++)
    {
        for(int j = 0; j < initial_hand_size; j++)
        {
            players[i]->add_card(game_deck.remove_card(0));
        }
    }
}

void NineNine::next_turn() {

    // implementation
}

void NineNine::start_game() {
    // implementation
    this->current_state = GameState::IN_PROGRESS;
}

void NineNine::calculate_scores() {

    // implementation
}

void NineNine::add_player(const std::string& playerName) {

    // implementation
}

void NineNine::show_game_status() const {

    // implementation
}

bool NineNine::is_game_over() const {
    // implementation
    return true;
}

void NineNine::end_game() {

    // implementation
}

void NineNine::show_all_players() const {
    // implementation
}