#include "Dealer.hpp"

Dealer::Dealer() : Entity("Dealer") {}

void Dealer::print_hand() {
    if(cards_in_hand == 1) {
        std::cout << name << "'s hand:\n";
        //(1)
        hand[0].print_one(); std::cout << " " << "╔═════════╗\n"; 
        //(2)
        hand[0].print_two(); std::cout << " " << "║ ▓▒▓▒▓▒▓ ║\n";   
        //(3)
        hand[0].print_three(); std::cout << " " << "║ ▓▒▓▒▓▒▓ ║\n"; 
        //(4)
        hand[0].print_four(); std::cout << " " << "║ ▓▒▓▒▓▒▓ ║\n"; 
        //(3)
        hand[0].print_three(); std::cout << " " << "║ ▓▒▓▒▓▒▓ ║\n";
        //(5)
        hand[0].print_five(); std::cout << " " << "║ ▓▒▓▒▓▒▓ ║\n"; 
        //(6)
        hand[0].print_six(); std::cout << " " << "╚═════════╝\n"; 
        //hand value
        std::cout << "Hand value: " << get_hand_value() << endl;
    } else {
        Entity::print_hand();
    }
}

/*
Dealer class is useless at the moment. Perhaps it will become useful
when the game supports multiple players.
*/