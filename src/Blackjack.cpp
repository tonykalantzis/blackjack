#include "Blackjack.hpp"

Blackjack::Blackjack() {
    // intro
    std::cout << "Welcome to Blackjack!" << endl << endl;

    //shuffle the deck
    deck.shuffle_deck();
}

void Blackjack::start() {
    // initialize a player with 1000 starting money
    std::cout << "Enter your name: ";
    string name;
    getline(std::cin, name);
    Player1.set_name(name);
    std::cout << endl;

    std::cout << Player1 << " has just sat down. Starting money: " << Player1.get_money() << endl << endl;
}

void Blackjack::round_start() {
    // player inputs bet at the start of the round
    std::cout << Player1 << "'s money: " << Player1.get_money() << endl << endl;
    Player1.input_bet();
    std::cout << endl;

    // dealer always draws the first card
    Dealer.draw(deck);
}

void Blackjack::player_turn() {
    std::cout << "-----" << Player1 <<"'s Turn-----" << endl;

    // player automatically draws his first 2 cards
    std::cout << Player1 << " draws!" << endl;
    Player1.draw_two(deck);

    string play;

    // get player's choice
    bool stand = false;

    if (Player1.get_hand_value() == 21) { // check for blackjack
        std::cout << "Blackjack! " << Player1 << " stands!" << endl << endl;
        stand = true;
    }

    while (!stand) {
        // ask if player wants to hit or stand
        string choice;
        if (Player1.get_cards_in_hand() == 2)   // player can only double after being dealt the first 2 cards
            std::cout << "What will you do?" << endl << "1. Hit" << endl << "2. Stand" << endl << "3. Double" << endl;
        else
            std::cout << "What will you do?" << endl << "1. Hit" << endl << "2. Stand" << endl;
        std::cin >> choice;

        // if hit was chosen
        if (choice == "1") {
            std::cout << Player1 << " hits!" << endl;
            Player1.draw(deck);

            if (Player1.get_hand_value() == 21) {
                std::cout << Player1 << " stands at 21." << endl;
                stand = true;
            }
            if (Player1.get_hand_value() > 21) {

                bool ace_in_hand = false;
                // check if any aces are in hand to convert their values from 11 -> 1
                // STILL NEEDS WORK; CODE IS INCOMPLETE
                int count;
                for (auto c : Player1.return_hand_cards()) {
                    if (c.get_points() == 11) {
                        count++;
                        if (count > 1)
                            Player1.set_hand_value(Player1.get_hand_value() - 10);
                    //    Player1.set_hand_value(Player1.get_hand_value() - 10);
                        ace_in_hand = true;
                        break;
                    }
                }
                if (ace_in_hand)
                    continue;

                std::cout << "Busted!" << endl;
                stand = true;
                Player1.set_busted(true);
            }
        }
        // if stand was chosen
        else if (choice == "2") {
            std::cout << Player1 << " stands at " << Player1.get_hand_value() << endl;
            stand = true;
        }
        // if double was chosen
        else if (choice == "3" && Player1.get_cards_in_hand() == 2) {
            if (Player1.get_bet() > Player1.get_money())    // check if bet is legal
                std::cout << "Not enough money to double bet." << endl << endl; 
            else {
                std::cout << Player1 << " doubles!" << endl;
                Player1.double_bet();
                Player1.draw(deck);

                stand = true;   // player automatically stands after doubling
                
                if (Player1.get_hand_value() > 21) {    // check for busted
                    std::cout << "Busted!" << endl;
                    Player1.set_busted(true);
                }
                else 
                    std::cout << Player1 << " stands at " << Player1.get_hand_value() << endl;
            }
        }
        // if invalid choice
        else {
            std::cout << "Invalid choice." << endl;
            continue;
        }
    }
    std::cout << endl;
}

void Blackjack::dealer_turn() {
    std::cout << "-----Dealer's Turn-----" << endl;
    // dealer stands at 17 and above
    while (Dealer.get_hand_value() < 17) {
        std::cout << "Dealer hits" << endl;
        Dealer.draw(deck);
        std::cout << endl;
    }

    // check if dealer busted and print the appropriate message
    if (Dealer.get_hand_value() <= 21)
        std::cout << "Dealer stands at " << Dealer.get_hand_value() << endl;
    else {
        Dealer.set_busted(true);
        std::cout << "Dealer busted!" << endl;
    }
    std::cout << endl;
}

string Blackjack::get_winner() {
    // return the winner
    if (Dealer.is_busted() && Player1.is_busted())
        return "No one";
    else if (Player1.is_busted() || (!Dealer.is_busted() && Dealer.get_hand_value() >= Player1.get_hand_value()))
        return Dealer.get_name();
    else {
        Player1.add_money(2 * Player1.get_bet());
        return Player1.get_name();
    }
}

bool Blackjack::end() {
    // check if out of money
    if (Player1.get_money() <= 0) {
        std::cout << Player1 << " is out of money. Game ends." << endl;
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
        Player1.reset();
        Dealer.reset();
        return false;
    }
}