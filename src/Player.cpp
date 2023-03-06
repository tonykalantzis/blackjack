#include "Player.hpp"

Player::Player() : Entity("Player") {
    round_bet = 0;
}

int Player::get_bet() const {
    return round_bet;
}

void Player::input_bet() {
    std::cout << "Please give your bet: ";
    std::cin >> round_bet;

    while (money < round_bet || round_bet <= 0) {
        std::cout << "Illegal bet. Please give a legal bet: ";
        std::cin >> round_bet;
    }

    money -= round_bet;
}

void Player::double_bet() { // used when player chooses "double"
    money -= round_bet;
    round_bet *= 2;
}

int Player::get_money() const {
    return money;
}

void Player::add_money(int m) {
    money += m;
}
