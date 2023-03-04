#pragma once

#include "common.hpp"
#include "Player.hpp"

class Blackjack {
public:
    Blackjack();
    void start();
    void round_start();
    void player_turn();
    void dealer_turn();
    string get_winner();
    bool end();
private:
    Player Player1;
    Player Dealer;
    Deck deck;
};