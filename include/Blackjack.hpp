#pragma once

#include "common.hpp"
#include "Dealer.hpp"
#include "Player.hpp"

class Blackjack {
public:
    Blackjack();
    void start();
    void round_start();
    void player_turn();
    void dealer_turn();
    void round_end();
    bool end();
private:
    Player player1;
    Dealer dealer;
    Deck deck;
};