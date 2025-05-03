#ifndef CARD_EFFECT_INCLUDED
#define CARD_EFFECT_INCLUDED

#include "card_info.hpp"
#include "ninenine.h"

class CardEffect 
{
public:
    virtual ~CardEffect() = default;
    virtual void apply(NineNine& game, const CardInfo& card_info) = 0;
};

class NoEffect : public CardEffect
{
public:
    void apply(NineNine& game, const CardInfo& card_info) {}
};

class AddEffect : public CardEffect
{
public:
    void apply(NineNine& game, const CardInfo& card_info) 
    {
        int cur_cnt = game.get_current_counter();
        game.set_current_counter(cur_cnt + card_info.get_rank());
    }
}

class SubEffect : public CardEffect
{
public:
    void apply(NineNine& game, const CardInfo& card_info) 
    {
        int cur_cnt = game.get_current_counter();
        game.set_current_counter(cur_cnt - card_info.get_rank());
    }
}

// 迴轉
class ReverseEffect : public CardEffect 
{
public:
    void apply(NineNine& game, const CardInof& card_info)
    {
        game.set_turn_direction(-1);
    }
};

// 指定
class PointEffect : public CardEffect 
{
private:

    int user_input(NineNine& game)
    {
        game.show_all_players();
        
        int point;

        std::cout << "Please specify player's number: ";
        std::cin >> point;
        
        // Add input validation
        while (std::cin.fail() || point > game.get_players_size() || point < 1) {
            std::cin.clear(); // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
            std::cout << "Invalid input, please enter again: ";
            std::cin >> point;
        }

        return point;
    }

public:
    void apply(NineNine& game, const CardInfo& card_info)
    {
        int direction = game.get_turn_direction();
        int idx = user_input(game);
        game.set_current_player_index(idx - direction);
    }
};

#endif // CARD_EFFECT_INCLUDED