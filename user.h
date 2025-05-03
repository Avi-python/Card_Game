#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <string>
#include <vector>
#include "card.h"

class User {
private:
    std::string name;
    int score;
    Deck hand;

public:
    User(const std::string& user_name);
    
    std::string get_name() const;
    int get_score() const;
    const Deck& get_hand() const;
    
    void set_name(const std::string& user_name);

    void add_score(int points);
    void reset_score();

    void add_card(const Card& card);
    void clear_hand();
    Card remove_card(int index);
    virtual Card play_card() = 0;
    
    void show_hand(int cols) const;
};

class Human : public User {

public:
    Human(const std::string& user_name);

    Card play_card() override;
};

class Computer : public User {
public:
    Computer(const std::string& user_name);

    Card play_card() override;
};

#endif // USER_H_INCLUDED