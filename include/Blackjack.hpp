#pragma once

#include "common.hpp"
#include "Dealer.hpp"
#include "Player.hpp"

class Blackjack {
public:
    Blackjack();
    ~Blackjack();

    void start();
    void round_start();
    void player_turn();
    void dealer_turn();
    void round_end();
    bool end();
private:
    Dealer dealer;
    Deck deck;

    // multiple players; store them in a vector
    vector<Player*> players;
};