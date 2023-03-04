#pragma once

#include "common.hpp"

class Card {
public:
    enum Rank : small_int {
        ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
    };
    enum Suit : small_int {
        SPADE = 0, HEART, CLUB, DIAMOND
    };
    enum Status : small_int {
        IN_DECK = 0, IN_PLAY, DISCARDED
    };

    void init(Rank, Suit);
    small_int get_points() const;
    string get_rank() const;
    string get_suit() const;
    Status get_status() const;
    void set_status(Status);
    void print_2d();

    //rendering 6 part of a card
    void print_one();
    void print_two();
    void print_three();
    void print_four();
    void print_five();
    void print_six();

private:
    Rank rank;
    Suit suit;
    small_int points; // 1 or 11 for ACE, 10 for figures etc
    Status status;
};