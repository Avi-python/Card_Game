#include "ninenine.h"
#include <iostream>
#include <memory>

int main()
{
    NineNine game(4, 5);
    
    game.add_player("Jack");
    game.add_player("Daniel");
    game.add_player("Rose");
    
    game.setup_game(); // 洗牌 發牌
    
    game.start_game();
    while(!game.is_game_over())
    {
        // round by round
        game.next_turn();
        game.show_game_status();
    }
    
    game.show_all_players();
    
    
    game.end_game();

    return 0;
}