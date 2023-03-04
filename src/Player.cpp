#include "Player.hpp"

Player::Player(string given_name) {
    name = given_name;
    cards_in_hand = 0;
    money = 1000;
    round_bet = 0;
    hand_value = 0;
    busted = false;
    number_of_aces = 0;
}

void Player::input_bet() {
    std::cout << "Please give your bet: ";
    std::cin >> round_bet;

    // TODO: Check if "round_bet" is a string or not
    while (money < round_bet || round_bet <= 0) {
        std::cout << "Illegal bet. Please give a legal bet: ";
        std::cin >> round_bet;
    }

    money -= round_bet;
}

void Player::double_bet() { // used when player chooses Double
    money -= round_bet;
    round_bet *= 2;
}

int Player::get_bet() const {
    return round_bet;
}

int Player::get_money() const {
    return money;
}

int Player::get_hand_value() const {
    return hand_value;
}

int Player::get_cards_in_hand() const {
    return cards_in_hand;
}

void Player::set_name(string in_name) {
    name = in_name;
}

string Player::get_name() const {
    return name;
}

void Player::draw(Deck& deck) {
    Card card = deck.get_top_card();
    hand.push_back(card);
    cards_in_hand++;
    if (card.get_rank() == std::to_string(Card::ACE)) {
        number_of_aces++;
        if (number_of_aces > 1)
            hand_value -= 10;
    }
    hand_value += card.get_points();

    std::cout << get_name() << "'s hand:\n";
    if (get_name() == "Dealer")
        print_hand_2d();
    else
        print_hand_2d();
}

void Player::draw_two(Deck& deck) { // used at the start of player's turn. makes printing prettier :p
    // apla ebala thn draw se ena loop gia na to kanei 2 fores lol :p
    for (int i = 0 ; i < 2 ; i++) {
        Card card = deck.get_top_card();
        hand.push_back(card);
        cards_in_hand++;
        if (card.get_rank() == std::to_string(Card::ACE)) {
            number_of_aces++;
            if (number_of_aces > 1)
                hand_value -= 10;
        }
        hand_value += card.get_points();
    }

    std::cout << get_name() << "'s hand:\n";
    print_hand_2d();
}

void Player::print_hand() {
    for (small_int i = 0; i < cards_in_hand; i++)
        std::cout << hand[i].get_rank() << hand[i].get_suit() << " ";
    std::cout << endl << "Hand value: " << get_hand_value() << endl << "Current bet: " << get_bet() << endl << "Current money: " << get_money() << endl << endl;
}

void Player::print_dealer_hand() {
    for (small_int i = 0; i < cards_in_hand; i++)
        std::cout << hand[i].get_rank() << hand[i].get_suit() << " ";
    std::cout << endl << "Dealer's hand value: " << get_hand_value() << endl;
}

void Player::set_busted(bool status) {
    busted = status;
}

bool Player::is_busted() const {
    return busted;
}

void Player::add_money(int m) {
    money += m;
}

void Player::reset() {
    cards_in_hand = 0;
    round_bet = 0;
    hand_value = 0;
    busted = false;

    // epmty hand
    hand.erase(hand.begin(), hand.end());
}

const vector<Card>& Player::return_hand_cards() const {
    return hand;
}

void Player::set_hand_value(int val) {
    hand_value = val;
}

ostream& operator<< (ostream& left, const Player& right) {
    left << right.get_name();
    return left;
}
//------------------------------------------------------
void Player::draw_fake(Card& card) {
    

    hand.push_back(card);
    cards_in_hand++;
    if (card.get_rank() == "A") {
        std::cout << "Number of Aces: " << Player::number_of_aces << std::endl;
        Player::number_of_aces++;
        if (Player::number_of_aces > 1)
            hand_value -= 10;
    }
    hand_value += card.get_points();

    std::cout << get_name() << "'s hand: ";
    if (get_name() == "Dealer")
        print_dealer_hand();
    else
        print_hand();
} 

void Player::print_hand_2d() {
    //(1)
    for (small_int i = 0; i < cards_in_hand; i++) {
        hand[i].print_one(); std::cout << "   "; 
    } 
    std::cout << std::endl;
    //(2)
    for (small_int i = 0; i < cards_in_hand; i++) {
        hand[i].print_two(); std::cout << "   "; 
    }  
    std::cout << std::endl;
    //(3)
    for (small_int i = 0; i < cards_in_hand; i++) {
        hand[i].print_three(); std::cout << "   "; 
    }
    std::cout << std::endl;
    //(4)
    for (small_int i = 0; i < cards_in_hand; i++) {
        hand[i].print_four(); std::cout << "   "; 
    }
    std::cout << std::endl;
    //(3)
    for (small_int i = 0; i < cards_in_hand; i++) {
        hand[i].print_three(); std::cout << "   "; 
    }
    std::cout << std::endl;
    //(5)
    for (small_int i = 0; i < cards_in_hand; i++) {
        hand[i].print_five(); std::cout << "   "; 
    }
    std::cout << std::endl;
    //(6)
    for (small_int i = 0; i < cards_in_hand; i++) {
        hand[i].print_six(); std::cout << "   "; 
    }
    std::cout << endl << "Hand value: " << get_hand_value() << endl;
}