#include "Player.hpp"

Player::Player() : Entity("Player") {
    round_bet = 0;
}

int Player::get_bet() const {
    return round_bet;
}

void Player::input_bet() {
    bool bad_input = false;

    printf("    ╔═════════════╗\n");
    printf("    ║Give your bet║\n");
    printf("    ╠═════════════╝\n");
    printf("    ╚> ");

    std::cin >> round_bet;

    if (!std::cin) { // if cin failed (caused by user entering a string)
        std::cin.clear();   // clear cin
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignore bad input
        bad_input = true;   // raise bad_input flag
    }

    while (money < round_bet || round_bet <= 0 || bad_input) {
        printf("    ╔══════════════════════════════════════╗\n");
        printf("    ║Illegal bet. Please give a legal bet. ║\n");
        printf("    ╠══════════════════════════════════════╝\n");
        printf("    ╚> ");

        std::cin >> round_bet;

        if (!std::cin) { // if cin failed (caused by user entering a string)
            std::cin.clear();   // clear cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignore bad input
            bad_input = true;   // raise bad_input flag
        }
        else
            bad_input = false;
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
