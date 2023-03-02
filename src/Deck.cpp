#include "Deck.hpp"

Deck::Deck() {
    for (int s = 0; s < 4; s++)
        for (int i = 0 ; i <= 12 ; i++)  
            card[i+s*13].init((Card::Rank)(i + 1), (Card::Suit)s);

    top_card_pos = 0;
}

void Deck::shuffle_deck() {
    std::srand(std::time(NULL));
    std::random_shuffle(card, card + 52);
}

Card& Deck::get_top_card() {
    top_card_pos++;
    return card[top_card_pos-1];
}

void Deck::print_deck() {
    for (small_int i = top_card_pos; i < 52; i++)
        std::cout << card[i].get_rank() << card[i].get_suit() << " ";
    std::cout << std::endl;
}