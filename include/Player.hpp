#pragma once

#include "Entity.hpp"

class Player : public Entity {
public:
    Player();

    int get_bet() const;
    void input_bet();
    void double_bet();

    int get_money() const;
    void add_money(int);

    // void draw_fake(Card&);

private:
    int round_bet;
};
