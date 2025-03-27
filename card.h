#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED
#include <bits/stdc++.h>

#define CARD_WIDTH 17
#define CARD_HEIGHT 11

class Suit
{
public:
    virtual std::string to_string() const = 0;
    virtual std::vector<std::string> get_pattern() const = 0;
    virtual ~Suit() = default;
};

class Hearts : public Suit
{
public:
    std::string to_string() const override;
    std::vector<std::string> get_pattern() const override;
};

class Diamonds : public Suit
{
public:
    std::string to_string() const override;
    std::vector<std::string> get_pattern() const override;
};

class Clubs : public Suit
{
public:
    std::string to_string() const override;
    std::vector<std::string> get_pattern() const override;
};

class Spades : public Suit
{
public:
    std::string to_string() const override;
    std::vector<std::string> get_pattern() const override;
};

class Card
{
private:
    const Suit* suit;
    int rank;
public:
    Card(const Suit* s, int r);
    std::string to_string() const;
    std::vector<std::string> get_pattern() const;
    int get_rank() const;
    const Suit* get_suit() const;
};

class Deck
{
private:
    std::vector<Card> deck;
public:
    Deck() = default;
    Deck(const std::vector<Card>& cards);
    
    void set_deck(std::vector<Card>& input);
    void show_deck(int cols) const;
    
    void add_card(const Card& card);
    Card remove_card(int index);
    void clear();
    void shuffle();
    
    size_t size() const;
    bool empty() const;
    const Card& get_card(int index) const;
    const std::vector<Card>& get_cards() const;
};

#endif