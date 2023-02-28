#include "Blackjack.hpp"

int main() {
    Blackjack game;
    game.start();

 /*   // create extra aces :P
    Card ace1;
    ace1.init(Card::Rank::ACE, Card::Suit::CLUB);
    Card ace2;
    ace2.init(Card::Rank::ACE, Card::Suit::SPADE);
    Card ace3;
    ace3.init(Card::Rank::ACE, Card::Suit::DIAMOND); */

    do {
        game.round_start();
        game.player_turn();
        game.dealer_turn();

        string winner = game.get_winner();
        std::cout << winner << " wins." << endl;
    } while (!game.end());

    std::cout << "Thank you for playing! We hope to see you again!" << endl; 

 /*   Player P1;
    Deck Deck;
    P1.draw_fake(ace1);
    P1.draw_fake(ace2);
    P1.draw_fake(ace3); */
    
    return 0;
}