#include "user.h"
#include <iostream>

User::User(const std::string& user_name) : name(user_name), score(0) {}

std::string User::get_name() const {
    return name;
}

int User::get_score() const {
    return score;
}

const Deck& User::get_hand() const {
    return hand;
}

void User::set_name(const std::string& user_name) {
    name = user_name;
}

void User::add_score(int points) {
    score += points;
}

void User::reset_score() {
    score = 0;
}

void User::add_card(const Card& card) {
    hand.add_card(card);
}

void User::clear_hand() {
    hand.clear();
}

Card User::remove_card(int index) {
    return hand.remove_card(index);
}

void User::show_hand(int cols) const {
    std::cout << "Player: " << name << " (Score: " << score << ")\n";
    std::cout << "Hand:\n";
    
    hand.show_deck(cols);
} 

Computer::Computer(const std::string& user_name) : User(user_name) {}

Card Computer::play_card()
{
    // implementation
}

Human::Human(const std::string& user_name) : Human(user_name) {}

Card Human::play_card()
{
    // implementation
}
