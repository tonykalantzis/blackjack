#include "Blackjack.hpp"

#define MAX_PLAYERS 4

Blackjack::Blackjack() {
    std::cout << "Welcome to Blackjack!" << endl << endl;
    
    deck = new Deck;
    deck->shuffle_deck();

    dealer = new Dealer;
}

Blackjack::~Blackjack() {
    delete deck;
    delete dealer;
    for (auto p : players)
        delete p;
}

void Blackjack::start() {
    // starting num of players sitting
    int n_players;
    do {
        std::cout << "How many players want a sit at the table ? (1-4)" << endl;
        std::cin >> n_players;
        
        if (!std::cin) { // if cin failed (caused by user entering a string)
            std::cin.clear();   // clear cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignore bad input
        }
    } while (n_players < 1 || n_players > MAX_PLAYERS);
    std::cout << endl;

    // info for players
    for (int i = 0; i < n_players; i++) {

        Player* new_player = new Player;

        // get the player's name
        std::cout << "Player " << i+1 << " - Enter your name: ";
        string name;

        ////////////////////////////////////////////////////////////////////////////
        // UNKNOWN ERROR; If we don't put this
        // then we don't input the name of Player 1
        if (i == 0)
            getline(std::cin, name);
        ////////////////////////////////////////////////////////////////////////////

        getline(std::cin, name);
        new_player->set_name(name);
        std::cout << *new_player << " has just sat down. Starting money: " << new_player->get_money() << endl << endl;
    
        players.push_back(new_player);
    }
}

void Blackjack::round_start() {
    // all players draw/play before Dealer
    for (auto player : players) {
        // player inputs bet at the start of the round
        std::cout << *player << "'s money: " << player->get_money() << endl;
        player->input_bet();
        std::cout << endl;
    }

    // dealer always draws the first card
    dealer->draw(deck);
    dealer->print_hand();
    std::cout << endl;
}

void Blackjack::player_turn() {
    for (auto player : players) {
        std::cout << "-----" << *player <<"'s Turn-----" << endl;

        bool stand = false;

        // player automatically draws his first 2 cards
        std::cout << *player << " draws!" << endl;
        player->draw(deck);
        player->draw(deck);
        player->print_hand();

        // check for blackjack
        if (player->get_hand_value() == 21) {
            std::cout << "Blackjack! " << *player << " stands at 21!" << endl << endl;
            stand = true;
        }

        // get player's choice
        while (!stand) {
            // ask if player wants to hit or stand
            string choice;
            if (player->get_cards_in_hand() == 2)   // player can only double after being dealt the first 2 cards
                std::cout << "What will you do?" << endl << "1. Hit" << endl << "2. Stand" << endl << "3. Double" << endl;
            else
                std::cout << "What will you do?" << endl << "1. Hit" << endl << "2. Stand" << endl;
            std::cin >> choice;


            // if hit was chosen
            if (choice == "1") {
                std::cout << *player << " hits!" << endl;
                player->draw(deck);
                player->print_hand();

                // check for blackjack
                if (player->get_hand_value() == 21) {
                    std::cout << "Blackjack! ";
                    stand = true;
                }
            }
            // if stand was chosen
            else if (choice == "2")
                stand = true;
            // if double was chosen
            else if (choice == "3" && player->get_cards_in_hand() == 2) {
                // check if bet is legal
                if (player->get_bet() > player->get_money())
                    std::cout << "Not enough money to double bet." << endl << endl; 
                else {
                    std::cout << *player << " doubles!" << endl;
                    player->double_bet();
                    player->draw(deck);
                    player->print_hand();

                    stand = true;   // player automatically stands after doubling
                }
            }
            // if invalid choice
            else {
                std::cout << "Invalid choice." << endl;
                continue;
            }

            // check for busted
            if (player->get_hand_value() > 21) {
                std::cout << "Busted!" << endl;
                stand = true;
                player->set_busted(true);
            }
        }

        if (!player->is_busted())
            std::cout << *player << " stands at " << player->get_hand_value() << endl;
        
        std::cout << endl;
    }
}

void Blackjack::dealer_turn() {
    std::cout << "-----Dealer's Turn-----" << endl;
    // dealer stands at 17 and above
    while (dealer->get_hand_value() < 17) {
        std::cout << "Dealer hits" << endl;
        dealer->draw(deck);
        dealer->print_hand();
        std::cout << endl;
    }

    // check if dealer busted and print the appropriate message
    if (dealer->get_hand_value() < 21)
        std::cout << "Dealer stands at " << dealer->get_hand_value() << endl;
    else if (dealer->get_hand_value() == 21)
        std::cout << "Blackjack! Dealer stands at 21" << endl;
    else {
        dealer->set_busted(true);
        std::cout << "Dealer busted!" << endl;
    }
    std::cout << endl;
}

void Blackjack::round_end() {
    // if dealer lost then all players (non-busted) win
    if (dealer->is_busted()) {
        for (auto player : players) {
            if (!player->is_busted()) {
                player->add_money(2 * player->get_bet());
                std::cout << *player <<  " wins!" << endl;
            }
        }
    }
    else {
        for (auto player : players) {
            if (!player->is_busted()) {
                if (dealer->get_hand_value() >= player->get_hand_value())
                    std::cout << "Dealer wins..." << endl;
                else {
                    std::cout << *player <<  " wins!" << endl;
                    player->add_money(2 * player->get_bet());
                }
            }
            else
                std::cout << "Dealer wins..." << endl;
        }
    }
}

bool Blackjack::end() {
    // check if some players are out of money => delete them
    for (int i = 0; i < (int)players.size(); i++) {
        if (players[i]->get_money() <= 0) {
            std::cout << *players[i] << " is out of money. " << *players[i] << " leaves the table." << endl;
            // remove player
            delete players[i];
            players.erase(players.begin() + i);
        }
    }

    // if all players are eliminated then the game ends
    if (players.size() <= 0)
        return true;

    // check if player wants to play again
    string play;
    std::cout << "Continue playing ? y/n: ";
    std::cin >> play;
    while (play != "n" && play != "N" && play != "y" && play != "Y") {
        std::cout << "Enter y or n: ";
        getline(std::cin, play);
    }
    std::cout << endl;
    // if player quits, return true
    if (play == "n" || play == "N")
        return true;
    
    // else, reset all hands and return false 
    for (auto player : players)
        player->reset();
    dealer->reset();
    return false;
}