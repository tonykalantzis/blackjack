#pragma once

#include "common.hpp"
#include <bits/stdc++.h>
#include "Card.hpp"
#include <random>     // For std::mt19937 and std::random_device

class Deck {
public:
    Deck();
    ~Deck();

    void shuffle_deck();
    Card& get_top_card();

private:
    // array with cards
    Card* cards;
    small_int top_card_pos;
};