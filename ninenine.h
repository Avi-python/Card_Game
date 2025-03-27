#ifndef NINENINE_H_INCLUDED
#define NINENINE_H_INCLUDED

#include "card.h"
#include "user.h"
#include <vector>
#include <memory>

enum class GameState {
    NOT_STARTED,
    IN_PROGRESS,
    FINISHED
};

class NineNine {
private:
    GameState current_state;
    std::vector<std::shared_ptr<User>> players;
    int current_player_index;
    int initial_hand_size;
    int max_players;
    Deck game_deck;
    
    void setup_deck();
    void deal_initial_cards();
    
public:
    NineNine(int maxPlayers = 4, int initialHandSize = 5);
    
    void add_player(const std::string& playerName);
    void remove_player(int playerIndex);
    void setup_game();
    
    void start_game();
    void end_game();
    bool is_game_over() const;
    GameState get_game_state() const;
    
    void next_turn();
    std::shared_ptr<User> get_current_player() const;
    
    void draw_card(int playerIndex);
    void play_card(int playerIndex, int cardIndex);
    
    void show_game_status() const;
    void show_all_players() const;
    
    void calculate_scores();
};

#endif // NINENINE_H_INCLUDED 