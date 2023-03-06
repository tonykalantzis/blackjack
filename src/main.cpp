
#include "Blackjack.hpp"

int main() {
    Blackjack* game = new Blackjack;
    game->start();

    do {
        game->round_start();
        game->player_turn();
        game->dealer_turn();
        game->round_end();
    } while (!game->end());

    std::cout << "Thank you for playing! We hope to see you again!" << endl;

    delete game;
    
    return 0;
}