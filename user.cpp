#include "user.h"
#include <iostream>

User::User(const std::string& userName) : name(userName), score(0) {}

std::string User::get_name() const {
    return name;
}

int User::get_score() const {
    return score;
}

const Deck& User::get_hand() const {
    return hand;
}

void User::set_name(const std::string& userName) {
    name = userName;
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

Card User::play_card(int index) {
    return hand.remove_card(index);
}

void User::show_hand(int cols) const {
    std::cout << "Player: " << name << " (Score: " << score << ")\n";
    std::cout << "Hand:\n";
    
    hand.show_deck(cols);
} 