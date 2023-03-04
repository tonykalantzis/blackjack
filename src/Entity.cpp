#include "Entity.hpp"

Entity::Entity() {
    name = "entity"; // default name
    cards_in_hand = 0;
    money = STARTING_MONEY;
    hand_value = 0;
    busted = false;
    number_of_aces = 0;
}

void Entity::set_name(string given_name) {
    name = given_name;
}

string Entity::get_name() const {
    return name;
}

int Entity::get_hand_value() const {
    // if you are busted while holding aces, try converting aces to 1 instead of 11
    if (number_of_aces && hand_value >21) {
        for (int i = 1 ; i <= number_of_aces ; i++) {
            if (hand_value-i*10 <= 21)
                return hand_value-i*10;
        }
        // if you are busted when ace=1, return the smallest possible hand value
        return hand_value-number_of_aces*10;
    }

    return hand_value;
}

int Entity::get_cards_in_hand() const {
    return cards_in_hand;
}

void Entity::print_hand() {
    std::cout << name << "'s hand:\n";
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

void Entity::draw(Deck &deck) {
    Card card = deck.get_top_card();
    hand.push_back(card);
    cards_in_hand++;
    hand_value += card.get_points();

    if (card.get_rank() == "A") {
        number_of_aces++;
    }
}

void Entity::set_busted(bool status) {
    busted = status;
}

bool Entity::is_busted() const {
    return busted;
}

void Entity::reset() {
    cards_in_hand = 0;
    hand_value = 0;
    busted = false;
    number_of_aces = 0;
    // epmty hand
    hand.erase(hand.begin(), hand.end());
}

ostream& operator<< (ostream& left, const Entity& right) {
    left << right.name;
    return left;
}