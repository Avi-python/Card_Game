#include "ninenine.h"
#include "card_effect.h"

#include <iostream>
#include <algorithm>
#include <random>

NineNine::NineNine(int maxPlayers, int initialHandSize) 
    : current_state(GameState::NOT_STARTED),
      current_player_index(0),
      initial_hand_size(initialHandSize),
      max_players(maxPlayers),
      turn_direction(1),
      current_counter(0) {}

void NineNine::setup_game() {
    
    this->setup_deck();
    this->deal_initial_cards();
    this->current_player_index = 0;
}

void NineNine::set_turn_direction(int val)
{
    turn_direction = val;
}

int NineNine::get_turn_direction() const
{
    return turn_direction;
}

void NineNine::set_current_player_index(int val)
{
    current_player_index = val;
}

int NineNine::get_current_player_index() const
{
    return current_player_index;
}

void NineNine::set_current_counter(int val)
{
    current_counter = val;
}

int NineNine::get_current_counter()
{
    return current_counter;
}

void NineNine::setup_deck() {
    std::vector<Card> cards;
    
    Hearts hearts;
    Diamonds diamonds;
    Clubs clubs;
    Spades spades;
    
    // Create suit objects
    std::vector<Suit*> suits = {
        new Hearts(), new Diamonds(), new Clubs(), new Spades()
    };
    
    // Effect factory function
    auto createEffect = [](int rank) -> CardEffect* {
        // TODO
        // if (rank == 4) return new ReverseEffect();
        // if (rank == 5) return new PointEffect();
        return new AddEffect();
    };
    
    // Create all cards
    for (int rank = 1; rank <= 13; ++rank) {
        for (auto suit : suits) {
            cards.push_back(Card(suit, createEffect(rank), rank));
        }
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

    std::shared_ptr<User> player = players[current_player_index];
    Card card = player->play_card();
    CardInfo card_info(card.get_rank(), card.get_suit(), current_player_index);
    card.get_effect()->apply(this*, card_info);

    std::cout << "round over, next player! " << '\n';

    // go to next round
    current_player_index = current_player_index + turn_direction;
}

void NineNine::start_game() {
    this->current_state = GameState::IN_PROGRESS;

    std::cout << "遊戲開始 !" << '\n';
}

void NineNine::calculate_scores() {

    // implementation
}

void NineNine::add_player(const std::string& player_name, bool is_human) {
    
    if(is_human)
    {
        players.push_back(std::make_shared<Human>(player_name));
        std::cout << "已經新增人類玩家: " << player_name << '\n';
        
    }
    else
    {
        players.push_back(std::make_shared<Computer>(player_name));
        std::cout << "已經新增電腦玩家: " << player_name << '\n';
    }
}

int NineNine::get_players_size() const
{
    return players.size();
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

    for(int i = 0; i < players.size(); i++)
    {
        std::cout << i + 1 << " : " << players[i]->get_name() << '\n';
    }

}