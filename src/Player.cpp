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

// void Player::draw_fake(Card& card) {
    

//     hand.push_back(card);
//     cards_in_hand++;
//     if (card.get_rank() == "A") {
//         std::cout << "Number of Aces: " << Player::number_of_aces << std::endl;
//         Player::number_of_aces++;
//         if (Player::number_of_aces > 1)
//             hand_value -= 10;
//     }
//     hand_value += card.get_points();

//     std::cout << get_name() << "'s hand: ";
//     if (get_name() == "Dealer")
//         print_dealer_hand();
//     else
//         print_hand();
// } 