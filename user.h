#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <string>
#include <vector>
#include "card.h" // 引入卡牌定义

class User {
private:
    std::string name;
    int score;
    Deck hand; // 使用Deck作为手牌容器，替代std::vector<Card>

public:
    User(const std::string& userName);
    
    std::string get_name() const;
    int get_score() const;
    const Deck& get_hand() const;
    
    void set_name(const std::string& userName);
    void add_score(int points);
    void reset_score();
    
    void add_card(const Card& card);
    void clear_hand();
    Card play_card(int index); // 打出一张卡牌
    
    void show_hand(int cols) const;
};

#endif // USER_H_INCLUDED 