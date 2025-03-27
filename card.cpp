#include "card.h"
#include <sstream>
#include <bits/stdc++.h>

static std::string center(int width, const std::string& str) {
    int len = str.length();
    if(width < len) { return str; }

    int diff = width - len;
    int pad1 = diff/2;
    int pad2 = diff - pad1;
    return std::string(pad1, ' ') + str + std::string(pad2, ' ');
}

std::string Hearts::to_string() const 
{
    return "Hearts";
}

std::vector<std::string> Hearts::get_pattern() const 
{
    return {
        "  #   #  ",
        " ### ### ",
        "#### ####",
        " ####### ",
        "  #####  ",
        "   ###   ",
        "    #    "
    };
}

std::string Diamonds::to_string() const 
{
    return "Diamonds";
}

std::vector<std::string> Diamonds::get_pattern() const 
{
    return {
        "    #    ",
        "   ###   ",
        "  #####  ",
        " ####### ",
        "  #####  ",
        "   ###   ",
        "    #    "
    };
}

std::string Clubs::to_string() const 
{
    return "Clubs";
}

std::vector<std::string> Clubs::get_pattern() const 
{
    return {
        "    #    ",
        "   ###   ",
        " ## # ## ",
        "#########",
        " # ### # ",
        "   ###   ",
        " ####### "
    };
}

std::string Spades::to_string() const 
{
    return "Spades";
}

std::vector<std::string> Spades::get_pattern() const 
{
    return {
        "    #    ",
        "  #####  ",
        " ####### ",
        " ####### ",
        " ####### ",
        "   ###   ",
        " ####### "
    };
}

Card::Card(const Suit* s, int r) : suit(s), rank(r) {}

std::string Card::to_string() const 
{
    return std::to_string(rank) + "," + suit->to_string();
}

int Card::get_rank() const
{
    return rank;
}

const Suit* Card::get_suit() const
{
    return suit;
}

std::vector<std::string> Card::get_pattern() const
{
    std::vector<std::string> result;
    std::ostringstream oss;
    std::string srank = std::to_string(rank);
    result.push_back(std::string(CARD_WIDTH, '-'));
    oss << "|" << std::left << std::setw(CARD_WIDTH - 2) << srank << "|";
    result.push_back(oss.str());
    oss.str("");
    oss.clear();
    for(std::string s : suit->get_pattern()) 
    {
        result.push_back("|" + center(CARD_WIDTH - 2, s) + "|");
    }
    oss << "|" << std::right << std::setw(CARD_WIDTH - 2) << srank << "|";
    result.push_back(oss.str());
    result.push_back(std::string(CARD_WIDTH, '-'));

    return result;
}

// Deck 构造函数
Deck::Deck(const std::vector<Card>& cards) : deck(cards) {}

void Deck::set_deck(std::vector<Card>& input)
{
    deck = input;
}

void Deck::show_deck(int cols) const
{
    int n = deck.size();
    std::vector<std::vector<std::string>> cards;

    for(int i = 0; i < n; i++)
    {
        cards.push_back(deck[i].get_pattern());
    }

    for(int b = 0; b < n; b += cols)
    {
        for(int i = 0; i < CARD_HEIGHT; i++)
        {
            for(int j = b;j < n && j < cols + b; j++)
            {
                std::cout << cards[j][i] << ' ';
            }
            std::cout << '\n';
        }
        std::cout << "\n";
    }
}

void Deck::add_card(const Card& card)
{
    deck.push_back(card);
}

Card Deck::remove_card(int index)
{
    if (index < 0 || index >= deck.size())
    {
        throw std::out_of_range("Card index out of range");
    }
    
    Card removed = deck[index];
    deck.erase(deck.begin() + index);
    return removed;
}

void Deck::clear()
{
    deck.clear();
}

void Deck::shuffle()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
}

size_t Deck::size() const
{
    return deck.size();
}

bool Deck::empty() const
{
    return deck.empty();
}

const Card& Deck::get_card(int index) const
{
    if (index < 0 || index >= deck.size())
    {
        throw std::out_of_range("Card index out of range");
    }
    
    return deck[index];
}

const std::vector<Card>& Deck::get_cards() const
{
    return deck;
}