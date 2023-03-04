#include "Blackjack.hpp"

Blackjack::Blackjack() {
    // intro
    std::cout << "Welcome to Blackjack!" << endl << endl;

    //shuffle the deck
    deck.shuffle_deck();
}

void Blackjack::start() {
    // get the player's name
    std::cout << "Enter your name: ";
    string name;
    getline(std::cin, name);
    player1.set_name(name);
    std::cout << player1 << " has just sat down. Starting money: " << player1.get_money() << endl << endl;
}

void Blackjack::round_start() {
    // player inputs bet at the start of the round
    std::cout << player1 << "'s money: " << player1.get_money() << endl;
    player1.input_bet();
    std::cout << endl;

    // dealer always draws the first card
    dealer.draw(deck);
    dealer.print_hand();
    std::cout << endl;
}

void Blackjack::player_turn() {
    std::cout << "-----" << player1 <<"'s Turn-----" << endl;

    bool stand = false;

    // player automatically draws his first 2 cards
    std::cout << player1 << " draws!" << endl;
    player1.draw(deck);
    player1.draw(deck);
    player1.print_hand();

    // check for blackjack
    if (player1.get_hand_value() == 21) {
        std::cout << "Blackjack! " << player1 << " stands at 21!" << endl << endl;
        stand = true;
    }

    // get player's choice
    while (!stand) {
        // ask if player wants to hit or stand
        string choice;
        if (player1.get_cards_in_hand() == 2)   // player can only double after being dealt the first 2 cards
            std::cout << "What will you do?" << endl << "1. Hit" << endl << "2. Stand" << endl << "3. Double" << endl;
        else
            std::cout << "What will you do?" << endl << "1. Hit" << endl << "2. Stand" << endl;
        std::cin >> choice;


        // if hit was chosen
        if (choice == "1") {
            std::cout << player1 << " hits!" << endl;
            player1.draw(deck);
            player1.print_hand();

            // check for blackjack
            if (player1.get_hand_value() == 21) {
                std::cout << "Blackjack! ";
                stand = true;
            }
        }
        // if stand was chosen
        else if (choice == "2")
            stand = true;
        // if double was chosen
        else if (choice == "3" && player1.get_cards_in_hand() == 2) {
            // check if bet is legal
            if (player1.get_bet() > player1.get_money())
                std::cout << "Not enough money to double bet." << endl << endl; 
            else {
                std::cout << player1 << " doubles!" << endl;
                player1.double_bet();
                player1.draw(deck);
                player1.print_hand();

                stand = true;   // player automatically stands after doubling
            }
        }
        // if invalid choice
        else {
            std::cout << "Invalid choice." << endl;
            continue;
        }

        // check for busted
        if (player1.get_hand_value() > 21) {
            std::cout << "Busted!" << endl;
            stand = true;
            player1.set_busted(true);
        }
    }

    if (!player1.is_busted())
        std::cout << player1 << " stands at " << player1.get_hand_value() << endl;
    
    std::cout << endl;
}

void Blackjack::dealer_turn() {
    std::cout << "-----Dealer's Turn-----" << endl;
    // dealer stands at 17 and above
    while (dealer.get_hand_value() < 17) {
        std::cout << "Dealer hits" << endl;
        dealer.draw(deck);
        dealer.print_hand();
        std::cout << endl;
    }

    // check if dealer busted and print the appropriate message
    if (dealer.get_hand_value() < 21)
        std::cout << "Dealer stands at " << dealer.get_hand_value() << endl;
    else if (dealer.get_hand_value() == 21)
        std::cout << "Blackjack! Dealer stands at 21" << endl;
    else {
        dealer.set_busted(true);
        std::cout << "Dealer busted!" << endl;
    }
    std::cout << endl;
}

void Blackjack::round_end() {
    // print the winner
    if (dealer.is_busted() && player1.is_busted())
        std::cout << "No one wins..." << endl;
    else if (player1.is_busted() || (!dealer.is_busted() && dealer.get_hand_value() >= player1.get_hand_value()))
        std::cout << "Dealer wins..." << endl;
    else {
        player1.add_money(2 * player1.get_bet());
        std::cout << player1 <<  " wins!" << endl;
    }
}

bool Blackjack::end() {
    // check if out of money
    if (player1.get_money() <= 0) {
        std::cout << player1 << " is out of money. Game ends." << endl;
        return true;
    }

    // check if player wants to play again
    string play;
    std::cout << "Continue playing ? y/n: ";
    std::cin >> play;
    while (play != "n" && play != "N" && play != "y" && play != "Y") {
        std::cout << "Enter y or n: ";
        getline(std::cin, play);
    }
    
    // if player quits, return true
    if (play == "n" || play == "N")
        return true;
    // else, reset all hands and return false 
    else {   
        player1.reset();
        dealer.reset();
        return false;
    }
}