#pragma once

#include "common.hpp"
#include <bits/stdc++.h>
#include "Card.hpp"

class Deck {
public:
    Deck();
    
    void shuffle_deck();
    Card& get_top_card();
    void print_deck();

private:
    Card card[52];
    small_int top_card_pos;
};