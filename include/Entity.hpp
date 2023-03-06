// Entities can only draw 1 card at a time, get busted and reset. Bets will be managed from Player class

#pragma once

#define STARTING_MONEY 1000

#include "common.hpp"
#include "Deck.hpp"

class Entity {
public:
    Entity(string type);

    void set_name(string given_name);
    string get_name() const;

    int get_hand_value() const;
    int get_cards_in_hand() const;
    void print_hand();
    void print_dealer_hand();

    void draw(Deck* deck);

    void set_busted(bool);
    bool is_busted() const;

    void reset();

    friend ostream& operator<< (ostream&, const Entity&);
protected:
    vector<Card> hand;
    small_int cards_in_hand;
    string name;
    int money;
    int hand_value;
    bool busted;
    int number_of_aces;
};
